#include <iostream>
#include <stack>
using namespace std;

const int MAXSIZE = 100;
//�̷δ� �ִ� 100 by 100

bool maze[MAXSIZE + 2][MAXSIZE + 2];


bool mark[MAXSIZE + 1][MAXSIZE + 1] = { 0 };
// ��� 2d array�� �켱 0���� �ʱ�ȭ(0=������, 1=����)
// �� MAXSIZE +1 by MAXSIZE+1�� ���� ..? 

enum directions {N,NE,E,SE,S,SW,W,NW};

struct offsets
{
	int a, b;
}mov[8] = { {-1,0 }, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
//offsets�迭 mov ���� ( 8���� ������ ǥ�� )


struct Items
{
	Items(int xx = 0, int yy=0,int dd=0) : x(xx),y(yy),dir(dd){}
	int x, y, dir;
};
//����ü Items�� ( x, y, dir) 3���� ���� ���� ����ü
//dir = �̵��ҹ���.? ( x, y ) => ������ ��ǥ


template <class T>
ostream& operator << (ostream& os, stack<T>& s)
// ���ÿ� �ִ� �������� �ϳ��� ��� (������..?)
{
	// ������ ������ �������� ��� 
	// ������� = ������ �ϳ��� ���� �ٸ� �ӽ� ���ÿ� �־� ������ ��,
	// ���������� �� �ӽ� ���ÿ��� �ϳ��� ���� ����ϸ� ��

	stack<T> hjhj;
	while (!s.empty())
	{
		hjhj.push(s.top());
		s.pop();
	}
	while (!hjhj.empty())
	{
		os << "->" << hjhj.top();
		s.push(hjhj.top());
		hjhj.pop();
	}
	return os;

}

ostream& operator<<(ostream& os, Items& item)
// ����ü Items��� (x,y) ��ǥ
{
	//5���� Items�� ��µ� ������ �� �ٲٱ� ����
	static int count = 0;
	os << "(" << item.x << "," << item.y << ")";
	count++;
	if ((count % 5) == 0) cout << endl;
	return os;
}

void Path(const int m, const int p)
{

	// (1,1) start
	
	
	mark[1][1] = 1;
	
	stack<Items> hjstack;
	//m * p ���� items�� �Է¹��� �� �ִ� stack����

	Items tmp(1, 1, E);
	// (1,1) ���� ���ʹ������� ������ �ϴ� Item��ü tmp ����

	hjstack.push(tmp);
	// tmp �������� stack�� ����

	int nodes_visited = 1;

	while (!hjstack.empty())
	{
		
		tmp = hjstack.top();
		hjstack.pop();

		int i = tmp.x; int j = tmp.y; int d = tmp.dir;
		// ���ʺ��� Ž��

		while (d < 8) 
		//������ Ž��
		{
			int g = i + mov[d].a;
			int h = j + mov[d].b;
			//[i][j] -> [g][h] 

			//cout << "this time d = " << d << endl;
			//cout << g << h << endl;


			if ((g == m) && (h == p))
			//success
			{
				cout << hjstack;
				tmp.x = i; tmp.y = j; cout << "->" << tmp;
				tmp.x = m; tmp.y = p; cout << "->" << tmp << endl;
				cout << "#nodes visited = " << nodes_visited << " out of " << m*p << endl;
				return; 
				//����
			}

			if ((!maze[g][h]) && (!mark[g][h]))
			// ������ ���� �ƴ϶�� , �׸��� �մ��� ���̶��...? 
			{
				mark[g][h] = 1;
				// ������ ��ġ�� '1' �� mark

				tmp.x = i; tmp.y = j; tmp.dir = d + 1;
				hjstack.push(tmp);
				nodes_visited++;
				i = g; j = h; d = N;

			}
			else d++;
		}
		// while�� ����
	}
	cout << "No path in maze" << endl;
}

void getdata(istream& is, int& m, int& p)
{
	// maze(m by p) �� �о�鿩 maze�� ����
	//�����ڸ����� 1 ���� (����Ұ�)
	// �� �ܿ��� �о���δ�� ����
	is >> m >> p;
	// m by p �̷��̴�!!  -> �ʱ�ȭ �۾�
	
	for (int i = 0; i < m + 2;i++)
	{
		maze[i][0] = 1;
		maze[i][p + 1] = 1;
	}
	for (int j = 1;j <= p;j++)
	{
		maze[0][j] = 1;
		maze[m + 1][j] = 1;
	}
	for (int i = 1;i <= m;i++)
		for (int j = 1; j <= p;j++)
			is >> maze[i][j];
}