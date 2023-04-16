/*CH9. 가상함수와 추상클래스*/
/* : 다중상속의 모호성을 가상상속으로 해결 가능*/
/*가상함수는 virtual키워드로 선언된 함수*/
/*오버라이딩은 기본클래스의 가상함수의 파생클래스에서의 재정의 : */



#include <iostream>
using namespace std;
class Shape
{
public:
	void paint()
	{
		draw();
	}
	virtual void draw()
	{
		cout << "Shape::draw()called" << endl;
	}
};



#include <iostream>
using namespace std;
class A
{
	int s, x;
protected:
	void setS(int s) { this->s = s; }
	void setX(int x) { this->x = x; }
};
class B : private A
{

};

#include <iostream>
using namespace std;
class Base
{
	int a;
protected:
	void setA(int a) { this -> a = a; }
public:
	void showA() { cout << a << endl; }
};
class Derived : private Base
	/*이제 derived클래스까지는 protected와 showA접근 가능*/
	/*외부에서는 전부 접근 불가 (private처리) ,, 추후상속클래스에서도 private처리가 적용됨*/
	/*오직 자기자신까지만 유지하고 추후&외부에서 접근지정 바꿔버림*/
{
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b << endl; }
};
class GrandDerived : private Derived
{
private:
	int c;
protected:
	void setAB(int x)
	{
		setA(x);
		//원래대로라면 base를 상속받았으니 private제외 접근 가능해야하지만 derived로 상속될 private상속되어 seta, showa가 private이 되버림

	}
};

#include <iostream>
using namespace std;
class A
{
private:
	int a = 10;
protected:
	int b = 20;
public:
	int c = 30;
};
class B : protected A
{
public:
	//protected상속 하면 private a는 접근 불가
	/*void fa() { cout << a << endl; }*/
	//b랑 c은 접근 가능
	void fb() { cout << b << endl; }
	void fc() { cout << c << endl; }
};
int main()
{
	B hj;
	//외부에서 c에 접근 불가  <- protected 처리되어 상속클래스에서만 접근 가능
}

#include <iostream>
using namespace std;
class A
{
private:
	int a=10;
protected:
	int b=20;
public:
	int c=30;
};

class B : private A
/*A클래스를 private 상속하는 B클래스*/
{
public:
	//파생클래스 B에서 -> a접근불가 / b,c접근가능
	/*void fa() { cout << a << endl; }*/
	void fb() { cout << b << endl; }
	void fc() { cout << c << endl; }
};
int main()
{
	B hj;
	//외부에서는 이제 a,b,c전부 private ( 접근불가)
	hj.fb();
	hj.fc();
}
//private접근지정 ->파생클래스에서는 private제외 접근 가능
//외부에서는 -> 전부 private처리되어 접근 불가
#include <iostream>
#include <string>
using namespace std;
class TV
{
	int size;
public:
	TV(int size=20) { this->size = size; }
	int getSize() { return size; }
};
class WideTV : public TV
{
	bool videoIn;
public:
	WideTV(int size, bool videoIN) : TV(size)
	{
		this->videoIn = videoIN;
	}
	bool getVideoIn() { return videoIn; }
};
class SmartTV :public WideTV
{
	string ip;
public:
	SmartTV(int size, bool videoIN, string ip) : WideTV(size, videoIN)
	{
		this->ip = ip;
	}
	string getIP() { return ip; }
};
int main()
{
	SmartTV hj(100, true, "hjhj");
	cout<<hj.getSize()<<endl;
	cout<<hj.getVideoIn()<<endl;
	cout<<hj.getIP()<<endl;
}
