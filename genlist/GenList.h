#ifndef  GENLIST_H
#define GENLIST_H
using namespace std;

class GenList;

class GenListNode
// ���븮��Ʈ�� ���
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
	// tag : 1 -> *down (���� ��ü�� list)
};

class GenList
// ���븮��Ʈ
{
public:

	GenList() { first = NULL; }
	// ������
	
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

	GenListNode* first; //ù ��° GenListNode�� ����Ű�� ptr

	void Make(GenListNode*&);
	
	void Print(GenListNode*&);
	
	void Insert(GenListNode*&, char, char);
	// i �ڿ� j ����
	void Delete(GenListNode*&, char);
	// i ����

};

#endif