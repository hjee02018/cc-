/*CH9. �����Լ��� �߻�Ŭ����*/
/* : ���߻���� ��ȣ���� ���������� �ذ� ����*/
/*�����Լ��� virtualŰ����� ����� �Լ�*/
/*�������̵��� �⺻Ŭ������ �����Լ��� �Ļ�Ŭ���������� ������ : */



//#include <iostream>
//using namespace std;
//class Shape
//{
//public:
//	void paint()
//	{
//		draw();
//	}
//	virtual void draw()
//	{
//		cout << "Shape::draw()called" << endl;
//	}
//};



//#include <iostream>
//using namespace std;
//class A
//{
//	int s, x;
//protected:
//	void setS(int s) { this->s = s; }
//	void setX(int x) { this->x = x; }
//};
//class B : private A
//{
//
//};

//#include <iostream>
//using namespace std;
//class Base
//{
//	int a;
//protected:
//	void setA(int a) { this -> a = a; }
//public:
//	void showA() { cout << a << endl; }
//};
//class Derived : private Base
//	/*���� derivedŬ���������� protected�� showA���� ����*/
//	/*�ܺο����� ���� ���� �Ұ� (privateó��) ,, ���Ļ��Ŭ���������� privateó���� �����*/
//	/*���� �ڱ��ڽű����� �����ϰ� ����&�ܺο��� �������� �ٲ����*/
//{
//	int b;
//protected:
//	void setB(int b) { this->b = b; }
//public:
//	void showB() { cout << b << endl; }
//};
//class GrandDerived : private Derived
//{
//private:
//	int c;
//protected:
//	void setAB(int x)
//	{
//		setA(x);
//		//������ζ�� base�� ��ӹ޾����� private���� ���� �����ؾ������� derived�� ��ӵɋ� private��ӵǾ� seta, showa�� private�� �ǹ���
//
//	}
//};


//#include <iostream>
//using namespace std;
//class A
//{
//private:
//	int a = 10;
//protected:
//	int b = 20;
//public:
//	int c = 30;
//};
//class B : protected A
//{
//public:
//	//protected��� �ϸ� private a�� ���� �Ұ�
//	/*void fa() { cout << a << endl; }*/
//	//b�� c�� ���� ����
//	void fb() { cout << b << endl; }
//	void fc() { cout << c << endl; }
//};
//int main()
//{
//	B hj;
//	//�ܺο��� c�� ���� �Ұ�  <- protected ó���Ǿ� ���Ŭ���������� ���� ����
//}


//#include <iostream>
//using namespace std;
//class A
//{
//private:
//	int a=10;
//protected:
//	int b=20;
//public:
//	int c=30;
//};
//
//class B : private A
///*AŬ������ private ����ϴ� BŬ����*/
//{
//public:
//	//�Ļ�Ŭ���� B���� -> a���ٺҰ� / b,c���ٰ���
//	/*void fa() { cout << a << endl; }*/
//	void fb() { cout << b << endl; }
//	void fc() { cout << c << endl; }
//};
//int main()
//{
//	B hj;
//	//�ܺο����� ���� a,b,c���� private ( ���ٺҰ�)
//	hj.fb();
//	hj.fc();
//}
////private�������� ->�Ļ�Ŭ���������� private���� ���� ����
////�ܺο����� -> ���� privateó���Ǿ� ���� �Ұ�


//#include <iostream>
//#include <string>
//using namespace std;
//class TV
//{
//	int size;
//public:
//	TV(int size=20) { this->size = size; }
//	int getSize() { return size; }
//};
//class WideTV : public TV
//{
//	bool videoIn;
//public:
//	WideTV(int size, bool videoIN) : TV(size)
//	{
//		this->videoIn = videoIN;
//	}
//	bool getVideoIn() { return videoIn; }
//};
//class SmartTV :public WideTV
//{
//	string ip;
//public:
//	SmartTV(int size, bool videoIN, string ip) : WideTV(size, videoIN)
//	{
//		this->ip = ip;
//	}
//	string getIP() { return ip; }
//};
//int main()
//{
//	SmartTV hj(100, true, "hjhj");
//	cout<<hj.getSize()<<endl;
//	cout<<hj.getVideoIn()<<endl;
//	cout<<hj.getIP()<<endl;
//}