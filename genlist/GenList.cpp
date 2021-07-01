#include <iostream>
#include "GenList.h"
using namespace std;

void GenList::Make(GenListNode*& cur)
// 범용리스트 생성. 재귀사용.
{ 
	char i;
	cin >> i;

	if (i == ')') return;

	else if (i == '(')
	// sublist의 시작
	{

		cur = new GenListNode(1);
		cur->down = new GenListNode();

		GenListNode* tmp = cur->down;

		char hj;
		cin >> hj;
		while (hj != ')')
		{
			Make(tmp);
		}


		tmp->next = 0;
		cur = cur->next;
		Make(cur);
	}

	else
	// data 값을 읽었을 때 
	{
		cur = new GenListNode;
		cur->tag = 0;
		cur->data = i;
		cur = cur->next;
		Make(cur);
	}
	

}

void GenList::Print(GenListNode*& cur)
 // 범용리스트 출력
{
	while (cur)
	{
		if (cur->tag == 0)
			//GenListNode에 data값이 저장되어 있음
		{
			cout << cur->data;
			cur = cur->next;
		}
		else if (cur->tag == 1)
			//GenListNode에 *down값이 저장되어 있음. ( 리스트를 가르키는 ptr)
		{
			GenListNode* hj = cur->down;


			cout << "(";
			while(cur->next == 0)
			{
				Print(hj);
			}
			cout << ")";

			Print(cur->next);
		}
	}    
}

void GenList::Insert(GenListNode*& cur, char i, char j)
 // i data를 가진 노드 뒤에 j데이터를 가진 노드 삽입
{
	while (cur)
	{
		if (cur->tag == 0)
		{

			if (cur->data == 'i')
			{
				GenListNode* tmp;

				tmp = cur->next;
				tmp = new GenListNode(0, cur->next);
				tmp->data = j;
				Insert(tmp->next, i, j);
			}

			else
			{
				cur = cur->next;
				Insert(cur, i, j);
			}
		}
		else if (cur->tag == 1)
		{
			GenListNode* ptr;
			ptr = cur->down;
			while (ptr->next != 0)
			{
				Insert(ptr, i, j);
			}

			Insert(cur, i, j);

		}
	}
}

void GenList::Delete(GenListNode*& cur, char i)
 // 모든 i data 삭제
{
	while (cur)
	{
		if (cur->tag == 0)
		{

			if (cur->data == 'i')
			{
				GenListNode* tmp = cur->next->next;
				delete cur->next;
				cur->next = tmp;
				Delete(tmp, i);
			}

			else
			{
				cur = cur->next;
				Delete(cur, i);
			}
		}
		else if (cur->tag == 1)
		{
			GenListNode* tmp;
			tmp = cur->down;
			while (tmp)
			{
				Delete(tmp,i);
			}
			cur = cur->next;
			Delete(cur, i);
		}
	}
}