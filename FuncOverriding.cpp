/*순수가상함수를 가진 추상클래스 <- 객체생성불가 but 포인터 선언 은 가능*/
//순수가상함수 : 동적바인딩에 의해 거의 실행되지 않는 기본클래스의 가상함수의 코드를 아예 작성하지 않는것(구현부x)

//#include <iostream>
//using namespace std;
//
//template <class T>
//void print(T array[], int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		cout << array[i];
//	}
//	cout << endl;
//}
//void print(char array[], int n)
//{
//	for (int i = 0;i < n;i++)
//	{
//		cout << (int)array[i];
//	}
//	cout << endl;
//}
//int main()
//{
//	char hj[] = { 1,2,3,4,5 };
//	print(hj, 4);
//
//}


//#include <iostream>
//using namespace std;
//class Calc
//{
//	void input()
//	{
//		cout << "정수 2개를 입력>>";
//		cin >> a >> b;
//	}
//protected:
//	int a, b;
//	virtual int calc(int a, int b) = 0;
//	//순수가상함수 -> add나 sub로 구현
//public:
//	void run()
//	{
//		input();
//		cout<<"계산된 값은"<<calc(a, b)<<endl;
//	}
//};
//
//class Adder : public Calc
//{
//protected:
//	int calc(int a, int b)
//	{
//		return a + b;
//	}
//};
//
//class Sum : public Calc
//{
//protected:
//	int calc(int a, int b)
//	{
//		return a - b;
//	}
//};

//#include <iostream>
//using namespace std;
//class Calculator
//{
//public:
//	virtual int add(int a, int b) = 0;
//	virtual int sub(int a, int b) = 0;
//	virtual double avg(int a[], int size) = 0;
//	//순수가상함수3개를 가진 추상클래스
//};
//class GOODcal : public Calculator
////GOODcal가 객체생서가능한 클래스가 되려면 기본클래스의 순수가상함수를 모두 오버라이딩(재정의)해야함
//{
//public:
//	virtual int add(int a, int b)
//	{
//		return a + b;
//	}
//	virtual int sub(int a, int b)
//	{
//		return a - b;
//	}
//	virtual double avg(int a[], int size)
//	{
//		int sum = 0;
//		for (int i = 0;i < size;i++)
//		{
//			sum += a[i];
//		}
//		return sum / size;
//	}
//};
//int main()
//{
//	int a[] = { 1,2,3,4,5 };
//	Calculator* hj = new GOODcal(); //UPCASTING
//	cout<<"3+4 = "<<hj->add(3, 4)<<endl;
//	cout << "3-4 = " << hj->sub(3, 4) << endl;
//	cout << "a[]의 평균 = " << hj->avg(a, 5) << endl;
//
//
//}




///*기본클래스의 가상함수의 재정의 : 오버라이딩 -> 동적바인딩이 발생 -> 오버라이딩된 함수의 호출을 보장받음*/

//#include <iostream>
//using namespace std;
//class Shape
//{
//private:
//	Shape* next;
//protected:
//	virtual void draw() = 0;
//	//순수가상함수
//public:
//	Shape() { next = NULL; }
//	virtual ~Shape(){}
//	void paint() { draw(); }
//	Shape* add(Shape* p) { next = p; return p; }
//	Shape* getNext() { return next; }
//};
//class Circle : public Shape
//{
//protected:
//	virtual void draw() { cout << "Circle::draw()called" << endl; }
//	//기본클래스(추상클래스)의 순수가상함수의 재정의(오버라이딩) => 이 파생클래스는 정상구현가능
//};
//class Rect : public Shape
//{
//protected:
//	virtual void draw() { cout << "Rect::draw()called" << endl; }
//};
//
//int main()
//{
//	Shape* pstart = NULL;
//	Shape* plast;
//
//	pstart = new Circle();
//	plast = pstart;
//
//	plast = plast->add(new Rect());
//	plast = plast->add(new Circle());
//	plast = plast->add(new Rect());
//
//	Shape* hj = pstart;
//	while(hj!= NULL)
//	{
//		hj->paint();
//		hj = hj->getNext();
//	}
//
//	hj = pstart;
//	Shape* yhj;
//	while (hj!= NULL)
//	{
//		yhj = hj->getNext();
//		delete hj;
//		hj = yhj;
//	}
//}