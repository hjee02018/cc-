#ifndef  GENLIST_H
#define GENLIST_H
using namespace std;

class GenList;

class GenListNode
// 범용리스트의 노드
{
	friend class GenList;
public:
	GenListNode(bool t = false, GenListNode *n = NULL):tag(t),next(n),data(0){}
private:
	GenListNode* next;
	bool tag;
	union
	{
		char data;
		GenListNode* down;
	};
	// tag : 0 -> data
	// tag : 1 -> *down (원소 자체가 list)
};

class GenList
// 범용리스트
{
public:

	GenList() { first = NULL; }
	// 생성자
	
	void Make()
	{
		char a;
		cin >> a;
		Make(first);
	}

	void Print()
	{
		cout << "(";
		Print(first);
		cout << endl;
	}

	void Insert(char i, char j)
	{
		Insert(first, i, j);
	}

	void Delete(char i)
	{
		Delete(first, i);
	}

private:

	GenListNode* first; //첫 번째 GenListNode를 가르키는 ptr

	void Make(GenListNode*&);
	
	void Print(GenListNode*&);
	
	void Insert(GenListNode*&, char, char);
	// i 뒤에 j 삽입
	void Delete(GenListNode*&, char);
	// i 삭제

};

#endif