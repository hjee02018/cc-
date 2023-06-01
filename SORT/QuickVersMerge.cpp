// mergesort와 quicksort의 비교 


#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;



//퀵정렬
template <class T>
void QuickSort(T* a, const int left, const int right)
{
	if (left < right)
	{
		int i = left;
		int j = right + 1;
		int pivot = a[left];
		do {
			do i++;while (a[i] < pivot);
			do j--;while (a[j] > pivot);
			if (i < j) swap(a[i], a[j]);
		} while (i < j);
		swap(a[left], a[j]);
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);

	}
}


//합병정렬
void Merge(int* initList, int* mergedList, const int l, const int m, const int n)
// initList[l:m] 과 initList[m+1:n] 를 합병
// -> mergedList[l:n]
{
	int i1, iResult, i2;
	for (i1 = l, iResult = l, i2 = m + 1;i1 <= m && i2 <= n;iResult++)
	{
		if (initList[i1] <= initList[i2])
		{
			mergedList[iResult] = initList[i1];
			i1++;
		}
		else
		{
			mergedList[iResult] = initList[i2];
			i2++;
		}
	}
	copy(initList + i1, initList + m + 1, mergedList + iResult);
	copy(initList + i2, initList + n + 1, mergedList + iResult);
}


void MergePass(int* initList, int* resultList, const int n, const int s)
{
	int i;
	for (i = 1;i <= n - 2 * s + 1;i += 2 * s)
		Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
	if ((i + s - 1) < n) Merge(initList, resultList, i, i + s - 1, n);
	else copy(initList + i, initList + n + 1, resultList + i);
}


void MergeSort(int* a, const int n)
// a[1:n]을 합병정렬
{
	int* tmpList = new int[n + 1]; // 임시list
	for (int l = 1;l < n;l *= 2)
	{
		MergePass(a, tmpList, n, l);
		l *= 2;
		MergePass(tmpList, a, n, l);
	}
	delete[]tmpList;
}



int main(int argc, char* argv[])
{
	freopen("input.txt", "r", stdin);
	int* hj = new int[3];
	clock_t sorted_merge_result[3];
	clock_t sorted_quick_result[3];
	for (int i = 0;i < 3;i++)
	{
		int N;
		cin >> N;
		hj[i] = N;
		//cin >> hj[i];

		//N개의 정렬된 data 생성

		int* arr = new int[N];

		for (int j = 0;j < N;j++)
		{
			arr[j] = j;
			// 0부터 오름차순으로 정렬된 data list를 입력받음
		}



		clock_t start;
		clock_t end;
		
		start = clock();
		MergeSort(arr, N);
		end = clock();
		sorted_merge_result[i] = end - start;

		for (int j = 0;j < N;j++)
		{
			arr[j] = j;
			// 0부터 오름차순으로 정렬된 data list를 입력받음
		}


		start = clock();
		QuickSort(arr,1, N);
		end = clock();
		sorted_quick_result[i] = end - start;


	}
	// sorted data의 개수 (1000,2000,3000)

	cout << "sorted		" <<"N="<< hj[0] << "		" << "N="<<hj[1] << "	" <<"N="<< hj[2]<<"\n";
	cout.precision(5);
	cout << fixed;
	cout << "Merge Sort	" << (double)sorted_merge_result[0]/CLOCKS_PER_SEC << "		" << (double)sorted_merge_result[1] / CLOCKS_PER_SEC << "		" << (double)sorted_merge_result[2] / CLOCKS_PER_SEC <<"\n";
	cout << "Quick Sort	" <<(double) sorted_quick_result[0]/CLOCKS_PER_SEC << "		" << (double)sorted_quick_result[1]/CLOCKS_PER_SEC << "	" << (double)sorted_quick_result[2]/CLOCKS_PER_SEC<<"\n";




	int* yhj = new int[3];
	clock_t random_merge_result[4][3];
	clock_t random_quick_result[4][3];
	for (int i = 0;i < 3;i++)
	{
		int N;
		cin >> N;
		yhj[i] = N;
		clock_t start;
		clock_t end;

		int* data1 = new int[N];
		int* data2 = new int[N];
		for (int tmp = 0;tmp < 3;tmp++)
		{
			for (int a = 0;a < N;a++)
			{
				data1[a] = rand();
				data2[a] = data1[a];
			}

			start = clock();
			MergeSort(data1, N);
			end = clock();
			random_merge_result[tmp][i] = end - start;

			start = clock();
			QuickSort(data2, 1, N);
			end = clock();
			random_quick_result[tmp][i] = end - start;
		}
		random_merge_result[3][i] = (random_merge_result[0][i] + random_merge_result[1][i] + random_merge_result[2][i]) / 3;
		random_quick_result[3][i] = (random_quick_result[0][i] + random_quick_result[1][i] + random_quick_result[2][i]) / 3;

	}

	cout << "\n";

	// random출력	
	cout << "random				" << "N="<<yhj[0] << "	" <<"N="<< yhj[1] << "	" << "N="<<yhj[2] << "\n";
	cout.precision(5);
	cout << fixed;
	cout << "Merge Sort	data1		" << (double)random_merge_result[0][0] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[0][1] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[0][2] / CLOCKS_PER_SEC << "\n";
	cout<<"		data2		"<< (double)random_merge_result[1][0] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[1][1] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[1][2] / CLOCKS_PER_SEC << "\n";
	cout << "		data3		" << (double)random_merge_result[2][0] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[2][1] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[2][2] / CLOCKS_PER_SEC << "\n";
	cout << "		average		" << (double)random_merge_result[3][0] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[3][1] / CLOCKS_PER_SEC << "		" << (double)random_merge_result[3][2] / CLOCKS_PER_SEC << "\n";


	cout << "Quick Sort	data1		" << (double)random_quick_result[0][0] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[0][1] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[0][2] / CLOCKS_PER_SEC << "\n";
	cout.precision(5);
	cout << fixed;
	cout << "		data2		" << (double)random_quick_result[1][0] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[1][1] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[1][2] / CLOCKS_PER_SEC << "\n";
	cout << "		data3		" << (double)random_quick_result[2][0] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[2][1] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[2][2] / CLOCKS_PER_SEC << "\n";
	cout << "		average		" << (double)random_quick_result[3][0] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[3][1] / CLOCKS_PER_SEC << "		" << (double)random_quick_result[3][2] / CLOCKS_PER_SEC << "\n";
}
