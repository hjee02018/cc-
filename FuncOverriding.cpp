/*���������Լ��� ���� �߻�Ŭ���� <- ��ü�����Ұ� but ������ ���� �� ����*/
//���������Լ� : �������ε��� ���� ���� ������� �ʴ� �⺻Ŭ������ �����Լ��� �ڵ带 �ƿ� �ۼ����� �ʴ°�(������x)

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
//		cout << "���� 2���� �Է�>>";
//		cin >> a >> b;
//	}
//protected:
//	int a, b;
//	virtual int calc(int a, int b) = 0;
//	//���������Լ� -> add�� sub�� ����
//public:
//	void run()
//	{
//		input();
//		cout<<"���� ����"<<calc(a, b)<<endl;
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
//	//���������Լ�3���� ���� �߻�Ŭ����
//};
//class GOODcal : public Calculator
////GOODcal�� ��ü���������� Ŭ������ �Ƿ��� �⺻Ŭ������ ���������Լ��� ��� �������̵�(������)�ؾ���
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
//	cout << "a[]�� ��� = " << hj->avg(a, 5) << endl;
//
//
//}




///*�⺻Ŭ������ �����Լ��� ������ : �������̵� -> �������ε��� �߻� -> �������̵��� �Լ��� ȣ���� �������*/

//#include <iostream>
//using namespace std;
//class Shape
//{
//private:
//	Shape* next;
//protected:
//	virtual void draw() = 0;
//	//���������Լ�
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
//	//�⺻Ŭ����(�߻�Ŭ����)�� ���������Լ��� ������(�������̵�) => �� �Ļ�Ŭ������ ����������
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