#include <iostream>
using namespace std;
class Power
{
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch=0) { this->kick = kick;this->punch = punch; }
	void show() { cout << "kick = " << kick << "punch = " << punch; }
	Power& operator ++ ();
};
Power& Power::operator++()
{
	this->kick++;
	this->punch++;
	return *this;
}
int main()
{
	Power hj(3, 5);
	++hj;
	hj.show();
}


//#include <iostream>
//using namespace std;
//template <class T1, class T2>
//class GClass
//{
//	T1 data1;
//	T2 data2;
//public:
//	GClass() { data1 = 0; data2 = 0; }
//	void set(T1 a, T2 b)
//	{
//		data1 = a;
//		data2 = b;
//	}
//	void get(T1& a, T2& b)
//	{
//		a = data1;
//		b = data2;
//	}
//};
//int main()
//{
//	int a;
//	double b;
//	GClass<int, double> hj;
//	hj.set(2, 0.8);
//	int c;
//	double d;
//	hj.get(c, d);
//	cout << c << " " << d << endl;
//}

//class mystack
//{
//	int idx;
//	T data[100];
//public:
//	mystack() { idx = -1; }
//	void push(T element) 
//	{
//		if (idx == 99) { cout << "full"; return ; }
//		else data[++idx] = element;
//	}
//	T pop()
//	{
//		if (idx == -1)
//		{
//			cout << "empty" << endl;
//			return 0;
//		}
//		else return data[idx--];
//	}
//};
//class Point
//{
//	int x, y;
//public:
//	Point(int x = 0, int y = 0) { this->x = x;this->y = y; }
//	void show() { cout << x << " " << y << endl; }
//};
//
//int main()
//{
//	mystack <int*>hj;
//	int* p = new int[3];
//	for (int i = 0;i < 3;i++)
//	{
//		p[i] = 10 * (i+1);
//	}
//	hj.push(p);
//	int* q;
//	q = hj.pop();
//	for (int i = 0;i < 3;i++)
//	{
//		cout << q[i]<<" ";
//	}
//	cout << endl;
//
//	mystack <Point> yhj;
//	Point a(3, 4), b;
//	yhj.push(a);
//	b = yhj.pop();
//	b.show();
//
//	mystack <Point*> pt;
//	Point* pPoint = new Point(100,200);
//	pt.push(pPoint);
//	Point* ptr;
//	ptr = pt.pop();
//	ptr->show();
//
//	mystack <string> str;
//	string s = "hj is best";
//	str.push(s);
//	cout << str.pop();
//}
