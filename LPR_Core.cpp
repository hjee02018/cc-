// LPR_Core.cpp : DLL의 초기화 루틴을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "LPR_Core.h"

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

#ifdef _DEBUG
#pragma comment(lib, "opencv_world453d.lib")
#else
#pragma comment(lib, "opencv_world453.lib")
#endif

using namespace std;
using namespace cv;
using namespace dnn;

char CLASSES_[83][10] = {
		"1","2","3","4","5","6","7","8","9","0",
		// 가   나   다   라   마   거   너   더   러   머   버   서   어   저
		  "AA","AB","AC","AD","AE","AF","AG","AH","AI","AJ","AK","AL","AM","AN",
		  // 고   노   도   로   모   보   소   오   조   구   누   두   루   무   부   수   우   주
			"BA","BB","BC","BD","BE","BF","BG","BH","BI","BJ","BK","BL","BM","BN","BO","BP","BQ","BR",
			// 외   영   준   협   교   기   정   표
			  "CA","CB","CC","CD","CE","CF","CG","CH",
			  // 강   경   광   대   세   울   인   전   제   충   원   남   북   산   종   천
				"DA","DB","DC","DD","DE","DF","DG","DH","DI","DJ","DK","DL","DM","DN","DO","DP",
				// 하   허   호
				  "HA","HB","HC",
				  // 바   사   아   자   배   차   카   타   파
					"TA","TB","TC","TD","TE","TF","TG","TH","TI",
					// 육   해   공   국   합
					  "MA","MB","MC","MD","ME"
};


char CLASSES_H[83][10] = {
		"1","2","3","4","5","6","7","8","9","0",
		"가","나","다","라","마","거","너","더","러","머","버","서","어","저",
		"고","노","도","로","모","보","소","오","조","구","누","두","루","무","부","수","우","주",
		"외","영","준","협","교","기","정","표",
		"강","경","광","대","세","울","인","전","제","충","원","남","북","산","종","천",
		"하","허","호",
		"바","사","아","자","배","차","카","타","파",
		"육","해","공","국","합"
};

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 이 DLL이 MFC DLL에 대해 동적으로 링크되어 있는 경우
//		MFC로 호출되는 이 DLL에서 내보내지는 모든 함수의
//		시작 부분에 AFX_MANAGE_STATE 매크로가
//		들어 있어야 합니다.
//
//		예:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 일반적인 함수 본문은 여기에 옵니다.
//		}
//
//		이 매크로는 MFC로 호출하기 전에
//		각 함수에 반드시 들어 있어야 합니다.
//		즉, 매크로는 함수의 첫 번째 문이어야 하며
//		개체 변수의 생성자가 MFC DLL로
//		호출할 수 있으므로 개체 변수가 선언되기 전에
//		나와야 합니다.
//
//		자세한 내용은
//		MFC Technical Note 33 및 58을 참조하십시오.
//

// CLPRCoreApp

BEGIN_MESSAGE_MAP(CLPRCoreApp, CWinApp)
END_MESSAGE_MAP()

// CLPRCoreApp 생성

CLPRCoreApp::CLPRCoreApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CLPRCoreApp 개체입니다.

CLPRCoreApp theApp;


// CLPRCoreApp 초기화

BOOL CLPRCoreApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

void LogWrite(const char far* p, ...)
{
	va_list args;
	va_start(args, p);

	int n;
	char szBuffer[1024] = { 0 };
	char szLog[1000] = { 0 };

	if ((n = _vsnprintf(szBuffer, 1024 - 1, p, args)) > 0)
	{
		SYSTEMTIME	cur_time;
		::GetLocalTime(&cur_time);

		sprintf(szLog, _T("[%04.04d-%02.02d-%02.02d %02.02d:%02.02d:%02.02d.%03.03d] %s\n"),
			cur_time.wYear, cur_time.wMonth, cur_time.wDay, cur_time.wHour,
			cur_time.wMinute, cur_time.wSecond, cur_time.wMilliseconds,
			szBuffer);

		FILE* fp = fopen("LPR_Core.log", "a");
		fwrite(szLog, 1, strlen(szLog), fp);
		fclose(fp);
	}
	va_end(args);
}

typedef struct PlateInfo
{
	FILETIME	m_time;
	char		m_plateNo[20];
	char		m_plateDigit[6];
};

typedef struct ResultInfo
{
	int			m_tag;

	SYSTEMTIME	m_time;

	int			m_type;

	Rect		m_rect;
	int			m_count;
	char		m_plateNo[20];
	char		m_plateDigit[6];
	char		m_plateNoLocal1[3];
	char		m_plateNoLocal2[3];
	char		m_plateNoHead1;
	char		m_plateNoHead2;
	char		m_plateNoHead3;
	char		m_plateNoMiddle[3];
	char		m_plateNoDigit1;
	char		m_plateNoDigit2;
	char		m_plateNoDigit3;
	char		m_plateNoDigit4;

	// 4자리가 같은 버퍼리스트
	std::list<ResultInfo> bufflist;
};


list <ResultInfo> lprList;

class LPRCore
{
public:
	Net				m_detectNet;
	DetectionModel	m_detectModel;

	Net				m_recogNet;
	DetectionModel	m_recogModel;

	double			m_detectThreshold;
	double			m_recogThreshold;

	int				m_resultCount;
	ResultInfo		m_result[30];

	int				m_prePlateCount;
	PlateInfo		m_prePlateInfo[100];
};


int* WINAPI LPR_LoadYOLO()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LPRCore* core = new LPRCore();

	// detect
	///////////////////////////////////////////////////////
	char* dmodelConfig = "SURV/detection_model.cfg";
	char* dmodelWeights = "SURV/detection_model.weights";

	//Read in the neural network from the files
	core->m_detectNet = readNetFromDarknet(dmodelConfig, dmodelWeights);

	//Run on either CPU or GPU
	core->m_detectNet.setPreferableBackend(DNN_BACKEND_CUDA);
	core->m_detectNet.setPreferableTarget(DNN_TARGET_CUDA);

	core->m_detectModel = DetectionModel(core->m_detectNet);
	core->m_detectModel.setInputParams(1 / 255.0, Size(416, 416), Scalar(), true);

	// recog
	///////////////////////////////////////////////////////
	char* rmodelConfig = "SURV/recog_model.cfg";
	char* rmodelWeights = "SURV/recog_model.weights";

	//Read in the neural network from the files
	core->m_recogNet = readNetFromDarknet(rmodelConfig, rmodelWeights);

	//Run on either CPU or GPU
	core->m_recogNet.setPreferableBackend(DNN_BACKEND_CUDA);
	core->m_recogNet.setPreferableTarget(DNN_TARGET_CUDA);

	core->m_recogModel = DetectionModel(core->m_recogNet);
	core->m_recogModel.setInputParams(1 / 255.0, Size(256, 224), Scalar(), true);

	core->m_detectThreshold = 0.5;
	core->m_recogThreshold = 0.5;

	core->m_resultCount = 0;
	core->m_prePlateCount = 0;

	LogWrite("LPR core Loaded.. ");
	return (int*)core;
}


void WINAPI LPR_UnloadYOLO(int* ptr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LPRCore* core = (LPRCore*)ptr;

	delete core;

	*ptr = 0;

	LogWrite("LPR core Unloaded.. ");
}


// Get SYSTEMTIME DIFF
int  GetDiff(SYSTEMTIME time1, SYSTEMTIME time2)
{
	ULONGLONG diff;
	ULARGE_INTEGER t1, t2;
	FILETIME cft1, cft2;
	SystemTimeToFileTime(&time1, &cft1);
	SystemTimeToFileTime(&time2, &cft2);
	memcpy(&t1, &cft1, sizeof(t1));
	memcpy(&t2, &cft2, sizeof(t2));
	diff = (t1.QuadPart < t2.QuadPart) ? (t2.QuadPart - t1.QuadPart) : (t1.QuadPart - t2.QuadPart) / 10000;
	return diff;
}

void AlignResultInfo(ResultInfo* res)
{
	if (res->m_count == 0) // 8234
	{
		sprintf(res->m_plateNo, "%c%c%c%c",
			res->m_plateNoDigit1,
			res->m_plateNoDigit2,
			res->m_plateNoDigit3,
			res->m_plateNoDigit4);
	}
	else if (res->m_count == 3) /// 70허8234
	{
		sprintf(res->m_plateNo, "%c%c%s%c%c%c%c",
			res->m_plateNoHead2,
			res->m_plateNoHead3,
			res->m_plateNoMiddle,
			res->m_plateNoDigit1,
			res->m_plateNoDigit2,
			res->m_plateNoDigit3,
			res->m_plateNoDigit4);

	}
	else if (res->m_count == 4)
	{
		if (res->m_plateNoHead1 != NULL) /// 170허8234
		{
			sprintf(res->m_plateNo, "%c%c%c%s%c%c%c%c",
				res->m_plateNoHead1,
				res->m_plateNoHead2,
				res->m_plateNoHead3,
				res->m_plateNoMiddle,
				res->m_plateNoDigit1,
				res->m_plateNoDigit2,
				res->m_plateNoDigit3,
				res->m_plateNoDigit4);
		}
		else if (res->m_plateNoLocal2[0] != NULL) //경12가3456
		{
			sprintf(res->m_plateNo, "%s%c%c%s%c%c%c%c",
				res->m_plateNoLocal2,
				res->m_plateNoHead2,
				res->m_plateNoHead3,
				res->m_plateNoMiddle,
				res->m_plateNoDigit1,
				res->m_plateNoDigit2,
				res->m_plateNoDigit3,
				res->m_plateNoDigit4);
		}
	}
	else
		sprintf(res->m_plateNo, "%s%s%c%c%s%c%c%c%c",
			res->m_plateNoLocal1,
			res->m_plateNoLocal2,
			res->m_plateNoHead2,
			res->m_plateNoHead3,
			res->m_plateNoMiddle,
			res->m_plateNoDigit1,
			res->m_plateNoDigit2,
			res->m_plateNoDigit3,
			res->m_plateNoDigit4);
}

// 지역번호 보팅
void checkNoLocal(ResultInfo* res)
{
	res->bufflist.push_back(*res);
	map<char*, int> Local1;
	map<char*, int> Local2;
	list<ResultInfo>::iterator it;
	bool isLocal1 = false;
	bool isLocal2 = false;

	for (it = res->bufflist.begin(); it != res->bufflist.end(); it++)
	{
		if (it->m_plateNoLocal1[0] != NULL)
		{
			isLocal1 = true;
			//LogWrite("Local1 : %s", it->m_plateNoLocal1);
			/*후 처리1;수산->부산*/
			if (strcmp(it->m_plateNoLocal1, "수") == 0)
				strcpy(it->m_plateNoLocal1, "부");

			auto iter = Local1.find(it->m_plateNoLocal1);
			if (iter != Local1.end())
			{
				char NoLocal1[3];
				strcpy(NoLocal1, it->m_plateNoLocal1);
				iter->second++;
			}
			else
				Local1.insert(std::pair<char*, int>(it->m_plateNoLocal1, 1));
		}
		if (it->m_plateNoLocal2[0] != NULL)
		{
			isLocal2 = true;
			//LogWrite("Local2 : %s", it->m_plateNoLocal2);
			/*후 처리2;부수->부산*/
			if (strcmp(it->m_plateNoLocal2, "수") == 0 && strcmp(it->m_plateNoLocal1, "부"))
				strcpy(it->m_plateNoLocal2, "산");

			auto iter = Local2.find(it->m_plateNoLocal2);
			if (iter != Local2.end())
			{
				char NoLocal2[3];
				strcpy(NoLocal2, it->m_plateNoLocal2);
				iter->second++;
			}
			else
				Local2.insert(std::pair<char*, int>(it->m_plateNoLocal2, 1));
		}
	}

	int MAX1 = 0;
	for (map<char*, int>::iterator iter = Local1.begin(); iter != Local1.end(); iter++)
	{
		if (iter->second > MAX1)
		{
			MAX1 = iter->second;
			strcpy(res->m_plateNoLocal1, iter->first);
		}
	}

	int MAX2 = 0;
	for (map<char*, int>::iterator iter = Local2.begin(); iter != Local2.end(); iter++)
	{
		if (iter->second > MAX2)
		{
			MAX2 = iter->second;
			strcpy(res->m_plateNoLocal2, iter->first);
		}
	}

	//후 처리; 서 -> 서울
	if (strcmp(res->m_plateNoLocal2, "서") == 0 || strcmp(res->m_plateNoLocal2, "울") == 0)
	{
		strcpy(res->m_plateNoLocal1, "서");
		strcpy(res->m_plateNoLocal2, "울");
		isLocal1 = true;
	}
	// 후 처리 : 경or기->경기 
	if (strcmp(res->m_plateNoLocal2, "기") == 0 || strcmp(res->m_plateNoLocal2, "경") == 0)
	{
		strcpy(res->m_plateNoLocal1, "경");
		strcpy(res->m_plateNoLocal2, "기");
		isLocal1 = true;
	}
	// 후 처리 : 산 => 부산
	if (strcmp(res->m_plateNoLocal2, "산") == 0)
	{
		strcpy(res->m_plateNoLocal1, "부");
		strcpy(res->m_plateNoLocal2, "산");
		isLocal1 = true;
	}
	// 후 처리 : 산 => 부산
	if (strcmp(res->m_plateNoLocal2, "부") == 0 || strcmp(res->m_plateNoLocal1, "부") == 0)
	{
		strcpy(res->m_plateNoLocal1, "부");
		strcpy(res->m_plateNoLocal2, "산");
		isLocal1 = true;
	}

	if (isLocal1)
		res->m_count++;
	if (isLocal2)
		res->m_count++;

	LogWrite("Local Count : %d", res->m_count);
}

// 중간자 보팅
void checkNoMid(ResultInfo* res)
{
	res->bufflist.push_back(*res);
	int size_num = res->bufflist.size();
	list<ResultInfo>::iterator it;
	list<ResultInfo> tmp = res->bufflist;
	list <string> mid;
	bool isMid = false;

	for (it = res->bufflist.begin(); it != res->bufflist.end(); it++)
	{
		it->m_tag = 0;
		if (it->m_plateNoMiddle[0] != NULL)
		{
			//LogWrite("MID : %s", it->m_plateNoMiddle);
			isMid = true;
			for (list<ResultInfo>::iterator it2 = tmp.begin(); it2 != tmp.end(); it2++)
			{
				if (strcmp(it->m_plateNoMiddle, it2->m_plateNoMiddle) == 0)
					it->m_tag++;
			}
		}
	}

	list<ResultInfo>::iterator iter = res->bufflist.begin();
	int MAX = iter->m_tag;
	for (; iter != res->bufflist.end(); iter++)
	{
		if (iter->m_tag >= MAX)
		{
			MAX = iter->m_tag;
			strcpy(res->m_plateNoMiddle, iter->m_plateNoMiddle);
		}
	}
	res->m_type = 1;
	if (isMid)
		res->m_count++;
	LogWrite("Mid Count : %d", res->m_count);
}

// 차종번호3 보팅
void checkNoHead(ResultInfo* res)
{
	res->bufflist.push_back(*res);
	list<ResultInfo>::iterator it = res->bufflist.begin();
	map<char, int> Head1;
	map<char, int> Head2;
	map<char, int> Head3;

	bool isHead1 = false;
	bool isHead2 = false;
	bool isHead3 = false;

	for (; it != res->bufflist.end(); it++)
	{
		if (it->m_plateNoHead1 != NULL)
		{
			//LogWrite("Head1: %c", it->m_plateNoHead1);
			isHead1 = true;
			auto iter = Head1.find(it->m_plateNoHead1);
			if (iter != Head1.end())
			{
				char key = iter->first;
				iter->second++;
			}
			else
				Head1.insert(std::pair<char, int>(it->m_plateNoHead1, 1));
		}
		if (it->m_plateNoHead2 != NULL)
		{
			//LogWrite("Head2: %c", it->m_plateNoHead2);
			isHead2 = true;
			auto iter = Head2.find(it->m_plateNoHead2);
			if (iter != Head2.end())
			{
				char key = iter->first;
				iter->second++;
			}
			else
				Head2.insert(std::pair<char, int>(it->m_plateNoHead2, 1));
		}
		if (it->m_plateNoHead3 != NULL)
		{
			//LogWrite("Head3: %c", it->m_plateNoHead3);
			isHead3 = true;
			auto iter = Head3.find(it->m_plateNoHead3);
			if (iter != Head3.end())
			{
				char key = iter->first;
				iter->second++;
			}
			else
				Head3.insert(std::pair<char, int>(it->m_plateNoHead3, 1));
		}
	}

	int MAX1 = 0;
	for (map<char, int>::iterator iter = Head1.begin(); iter != Head1.end(); iter++)
	{
		if (iter->second > MAX1)
		{
			MAX1 = iter->second;
			res->m_plateNoHead1 = iter->first;
		}
	}

	int MAX2 = 0;
	for (map<char, int>::iterator iter = Head2.begin(); iter != Head2.end(); iter++)
	{
		if (iter->second > MAX2)
		{
			MAX2 = iter->second;
			res->m_plateNoHead2 = iter->first;
		}
	}

	int MAX3 = 0;
	for (map<char, int>::iterator iter = Head3.begin(); iter != Head3.end(); iter++)
	{
		if (iter->second > MAX3)
		{
			MAX3 = iter->second;
			res->m_plateNoHead3 = iter->first;
		}
	}

	if (isHead1)
		res->m_count++;
	if (isHead2)
		res->m_count++;
	if (isHead3)
		res->m_count++;

	// 후 처리 : 2자리->3자리 오인식
	if (res->m_plateNoHead1 == res->m_plateNoHead2 && MAX1 < 5)
	{
		res->m_count--;
		res->m_plateNoHead1 = NULL;
	}

	LogWrite("Head Count : %d", res->m_count);
}


int GetPlateNo(std::vector<int> pclassIds, ResultInfo* presult)
{
	bool ok = false;
	int size = pclassIds.size();
	if (size == 4)
	{
		if (pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = 0;
			presult->m_plateNoHead3 = 0;
			strcpy(presult->m_plateNoMiddle, "");
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%c%c%c%c",
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
	}
	else if (size == 5)
	{
		if (pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = 0;
			presult->m_plateNoHead3 = 0;
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%s%c%c%c%c",
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
	}
	else if (size == 6)
	{
		if (pclassIds[5] <= 9 &&
			pclassIds[4] <= 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = CLASSES_H[pclassIds[5]][0];
			presult->m_plateNoHead3 = CLASSES_H[pclassIds[4]][0];
			strcpy(presult->m_plateNoMiddle, "");
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%c%c%s%c%c%c%c",
				presult->m_plateNoHead2,
				presult->m_plateNoHead3,
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
		else if (pclassIds[5] <= 9 &&
			pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = 0;
			presult->m_plateNoHead3 = CLASSES_H[pclassIds[5]][0];
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%c%s%c%c%c%c",
				presult->m_plateNoHead3,
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
		else if (pclassIds[5] > 9 &&
			pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = 0;
			presult->m_plateNoHead3 = 0;
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%s%c%c%c%c",
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
	}
	else if (size == 7)
	{
		if (pclassIds[6] <= 9 &&
			pclassIds[5] <= 9 &&
			pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = CLASSES_H[pclassIds[6]][0];
			presult->m_plateNoHead3 = CLASSES_H[pclassIds[5]][0];
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%c%c%s%c%c%c%c",
				presult->m_plateNoHead2,
				presult->m_plateNoHead3,
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
	}
	else if (size == 8)
	{
		if (pclassIds[7] <= 9 &&
			pclassIds[6] <= 9 &&
			pclassIds[5] <= 9 &&
			pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, "");
			presult->m_plateNoHead1 = CLASSES_H[pclassIds[7]][0];
			presult->m_plateNoHead2 = CLASSES_H[pclassIds[6]][0];
			presult->m_plateNoHead3 = CLASSES_H[pclassIds[5]][0];
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%c%c%c%s%c%c%c%c",
				presult->m_plateNoHead1,
				presult->m_plateNoHead2,
				presult->m_plateNoHead3,
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
		if (pclassIds[7] > 9 &&
			pclassIds[6] <= 9 &&
			pclassIds[5] <= 9 &&
			pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, "");
			strcpy(presult->m_plateNoLocal2, CLASSES_H[pclassIds[7]]);
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = CLASSES_H[pclassIds[6]][0];
			presult->m_plateNoHead3 = CLASSES_H[pclassIds[5]][0];
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%s%c%c%s%c%c%c%c",
				presult->m_plateNoLocal2,
				presult->m_plateNoHead2,
				presult->m_plateNoHead3,
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
	}
	else if (size == 9)
	{
		if (pclassIds[8] > 9 &&
			pclassIds[7] > 9 &&
			pclassIds[6] <= 9 &&
			pclassIds[5] <= 9 &&
			pclassIds[4] > 9 &&
			pclassIds[3] <= 9 &&
			pclassIds[2] <= 9 &&
			pclassIds[1] <= 9 &&
			pclassIds[0] <= 9)
		{
			strcpy(presult->m_plateNoLocal1, CLASSES_H[pclassIds[8]]);
			strcpy(presult->m_plateNoLocal2, CLASSES_H[pclassIds[7]]);
			presult->m_plateNoHead1 = 0;
			presult->m_plateNoHead2 = CLASSES_H[pclassIds[6]][0];
			presult->m_plateNoHead3 = CLASSES_H[pclassIds[5]][0];
			strcpy(presult->m_plateNoMiddle, CLASSES_H[pclassIds[4]]);
			presult->m_plateNoDigit1 = CLASSES_H[pclassIds[3]][0];
			presult->m_plateNoDigit2 = CLASSES_H[pclassIds[2]][0];
			presult->m_plateNoDigit3 = CLASSES_H[pclassIds[1]][0];
			presult->m_plateNoDigit4 = CLASSES_H[pclassIds[0]][0];
			sprintf(presult->m_plateNo, "%s%s%c%c%s%c%c%c%c",
				presult->m_plateNoLocal1,
				presult->m_plateNoLocal2,
				presult->m_plateNoHead2,
				presult->m_plateNoHead3,
				presult->m_plateNoMiddle,
				presult->m_plateNoDigit1,
				presult->m_plateNoDigit2,
				presult->m_plateNoDigit3,
				presult->m_plateNoDigit4);
			ok = true;
		}
	}

	if (ok == true)
	{
		sprintf(presult->m_plateDigit, "%c%c%c%c",
			presult->m_plateNoDigit1,
			presult->m_plateNoDigit2,
			presult->m_plateNoDigit3,
			presult->m_plateNoDigit4);
		return 1;
	}
	return 0;
}

int WINAPI LPR_CheckYOLO(int* ptr, char* data, int width, int height, char* resultstr)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	LPRCore* core = (LPRCore*)ptr;

	SYSTEMTIME ctm;
	resultstr[0] = 0;
	int count = 0;

	Mat img = Mat(Size(width, height), CV_8UC3);
	img.data = (uchar*)data;

	std::vector<int> classIds;
	std::vector<float> confidence;
	std::vector<Rect> boxes;
	core->m_detectModel.detect(img, classIds, confidence, boxes, (float)0.5, (float)0.3);

	GetLocalTime(&ctm);

	Mat vimg = img.clone();

	for (int n = 0; n < classIds.size(); n++)
	{
		int diff = 0;
		int id = classIds[n];

		//if (confidence[n] > core->m_detectThreshold)
		{
			Rect rect;
			rect.x = boxes[n].x;
			rect.y = boxes[n].y;
			rect.width = boxes[n].width;
			rect.height = boxes[n].height;

			Mat pimg(img, rect);

			std::vector<int> pclassIds;
			std::vector<float> pconfidence;
			std::vector<Rect> pboxes;
			core->m_recogModel.detect(pimg, pclassIds, pconfidence, pboxes, (float)0.5, (float)0.3);

			if (pclassIds.size() <= 5)
			{
				continue;
			}

			std::vector<int> plocate(pclassIds.size());

			//  제일작은 y 구하기
			int miny = pimg.rows;
			int minInx = -1;
			for (int k = 0; k < pclassIds.size(); k++)
			{
				if (miny > pboxes[k].y)
				{
					miny = pboxes[k].y;
					minInx = k;
				}
			}
			if (minInx == -1)
				continue;

			int my = pboxes[minInx].y + (pboxes[minInx].height / 2);

			for (int k = 0; k < pclassIds.size(); k++)
			{
				if (my < pboxes[k].y)
					plocate[k] = 1;
				else
					plocate[k] = 0;
			}

			for (int k = 0; k < pclassIds.size(); k++)
			{
				int x = pboxes[k].x;

				for (int h = (k + 1); h < pclassIds.size(); h++)
				{
					if (x > pboxes[h].x)
					{
						int tmp1 = plocate[k];
						plocate[k] = plocate[h];
						plocate[h] = tmp1;

						tmp1 = pclassIds[k];
						pclassIds[k] = pclassIds[h];
						pclassIds[h] = tmp1;

						float tmp2 = pconfidence[k];
						pconfidence[k] = pconfidence[h];
						pconfidence[h] = tmp2;

						Rect tmp3 = pboxes[k];
						pboxes[k] = pboxes[h];
						pboxes[h] = tmp3;

						x = pboxes[k].x;
					}
				}
			}

			for (int k = 0; k < pclassIds.size(); k++)
			{
				int lo = plocate[k];

				for (int h = (k + 1); h < pclassIds.size(); h++)
				{
					if (lo <= plocate[h])
					{
						int tmp1 = plocate[k];
						plocate[k] = plocate[h];
						plocate[h] = tmp1;

						tmp1 = pclassIds[k];
						pclassIds[k] = pclassIds[h];
						pclassIds[h] = tmp1;

						float tmp2 = pconfidence[k];
						pconfidence[k] = pconfidence[h];
						pconfidence[h] = tmp2;

						Rect tmp3 = pboxes[k];
						pboxes[k] = pboxes[h];
						pboxes[h] = tmp3;

						lo = plocate[k];
					}
				}
			}

			ResultInfo result;
			int found = 0;
			ResultInfo m_result;
			char rbuff[100];
			if (GetPlateNo(pclassIds, &result) != 0)
			{
				result.m_time = ctm;
				list<ResultInfo>::iterator it;
				it = lprList.begin();

				if (lprList.size() == 0)
				{
					found = 2;
				}
				else
				{
					for (; it != lprList.end(); it++)
					{
						if (strcmp(it->m_plateDigit, result.m_plateDigit) == 0)
						{
							int diff = GetDiff(result.m_time, it->m_time);
							if (diff > 1500 && diff < 10000) // voting threshold : 1.5 sec 
								found = -1;
							else if (diff >= 10000 && it->m_type == 1)
								found = 11;
							else if (diff < 10000 && it->m_type == 1)
								found = 30;
							else
								found = 0;
							break;
						}
						else
						{
							found = 2;
						}
					}
				}

				if (found == 0) // 중복 -> 버퍼로 저장
				{
					it->bufflist.push_back(result);
					it->m_type = 7;
				}
				else if (found == 11) // 보팅 없이 기존 결과 사용
				{
					count++;
					result.m_rect = rect;
					it->m_time = result.m_time;
					/*result!*/
					if (it->bufflist.size() != 0)
						LogWrite("재등장 result : %s(%d)(%d)%2.2d%2.2d%2.2d", it->m_plateNo, it->bufflist.size(), it->m_count + 4, it->m_time.wHour, it->m_time.wMinute, it->m_time.wSecond);

					/*RESULT*/
					rectangle(vimg, rect, Scalar(0, 0, 255), 2);
					sprintf(rbuff, "result;LPR;%4.4d%2.2d%2.2d_%2.2d%2.2d%2.2d_%3.3d;%s;%d$%d$%d$%d;%d",
						it->m_time.wYear, it->m_time.wMonth, it->m_time.wDay, it->m_time.wHour, it->m_time.wMinute, it->m_time.wSecond, it->m_time.wMilliseconds,
						it->m_plateNo,
						result.m_rect.x, result.m_rect.y, result.m_rect.width, result.m_rect.height,
						it->bufflist.size());
					strcat(resultstr, rbuff);

				}
				else if (found == -1 && it->m_type != 1)
				{
					/*보팅*/
					it->m_count = 0;
					checkNoHead(&*it);
					checkNoMid(&*it);
					checkNoLocal(&*it);
					AlignResultInfo(&*it);
					count++;

					/*result!*/
					if (it->bufflist.size() != 0)
						LogWrite("result : %s(%d)(%d)", it->m_plateNo, it->bufflist.size(), it->m_count + 4);
					it->m_rect = rect;

					/*RESULT*/
					rectangle(vimg, rect, Scalar(0, 0, 255), 2);
					m_result = *it;
					sprintf(rbuff, "result;LPR;%4.4d%2.2d%2.2d_%2.2d%2.2d%2.2d_%3.3d;%s;%d$%d$%d$%d;%d",
						m_result.m_time.wYear, m_result.m_time.wMonth, m_result.m_time.wDay, m_result.m_time.wHour, m_result.m_time.wMinute, m_result.m_time.wSecond, m_result.m_time.wMilliseconds,
						m_result.m_plateNo,
						m_result.m_rect.x, m_result.m_rect.y, m_result.m_rect.width, m_result.m_rect.height,
						m_result.bufflist.size());
					strcat(resultstr, rbuff);
					it->m_type = 1;
					it->bufflist.~list();
				}
				else if (found == 2) // 새로운 번호판
				{
					result.m_type = 0;
					lprList.push_back(result);
					it = lprList.begin();
				}
				continue;
			}
			count++;
		}
	}
	return count;
}
