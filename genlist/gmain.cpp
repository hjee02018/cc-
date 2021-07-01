#include <iostream>
#include "GenList.h"
using namespace std;

int main()
{
	GenList Inlist;
	//GenList inlist 생성 

	Inlist.Make(); 
	//범용리스트 생성
	
	Inlist.Print();
	//범용리스트 출력,xx
	
	while (1)
	{
		/*
		1 : Insert
		2 : Delete
		3 : Print
		4 : 종료		
		*/

		// 명령어별 실행함수 지정

		int select;
		cin >> select;
		// 몇번의 명령어를 실행할지 입력받음.

		char i, j;
		if (select == 1)
			// 모든 i 노드 뒤에 j노드를 삽입
		{
			cin >> i >> j;
			Inlist.Insert(i, j);
		}

		else if (select == 2)
			// 모든 i노드 삭제
		{
			cin >> i;
			Inlist.Delete(i);
		}

		else if (select == 3)
			// 범용리스트 출력
		{
			Inlist.Print();
		}

		else if (select == 4)
			// 종료
		
		{
			break;
		}

		else
			// 명령어 입력오류
		{
			cout << "Wrong Command" << endl;
		}

	}
}
