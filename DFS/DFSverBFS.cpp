// DFS, BFS 
// 다차원 리스트 사용
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

int N, M, V;
int map[MAX][MAX];
bool isVisited[MAX];
queue <int>q;

void reset()
{
	for (int i = 1;i <= N;i++)
		isVisited[i] = 0;
}

void BFS(int V)
{
	q.push(V);
	isVisited[V] = true;
	while (!q.empty())
	{
		V = q.front();
		q.pop();
		for (int w = 1;w <= N;w++)
		{
			if (map[V][w] == 1 && isVisited[w] == 0)
			{
				q.push(w);
				isVisited[w] = true;
				cout << w << " ";
			}
		}
	}
}

void DFS(int V)
{
	isVisited[V] = true;
	cout << V << " ";
	for (int i = 1;i <= N;i++)
	{
		if (map[V][i] == 1 && isVisited[i] == 0)
		{
			DFS(i);
		}
	}
}

int main()
{
	cin >> N >> M >> V;
	for (int i = 0;i < M;i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	DFS(V);
	BFS(V);
	return 0;
}




//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> solution(vector<vector<int> > v) 
//{
//    vector<int> ans;
//    int arr_x[3];
//    int arr_y[3];
//
//    // 3점의 좌표 확인
//    for (int i = 0;i < 3;i++)
//    {
//        vector<int> tmp = v[i];
//        arr_x[i] = tmp.front();
//        arr_y[i] = tmp.back();
//    }
//    if (arr_x[0] == arr_x[1])
//        ans.push_back(arr_x[2]);
//    else if (arr_x[1] == arr_x[2])
//        ans.push_back(arr_x[0]);
//    else
//        ans.push_back(arr_x[1]);
//
//    if (arr_y[0] == arr_y[1])
//        ans.push_back(arr_y[2]);
//    else if (arr_y[1] == arr_y[2])
//        ans.push_back(arr_y[0]);
//    else
//        ans.push_back(arr_y[1]);
//
//
//    cout << "Hello Cpp" << endl;
//
//    return ans;
//}