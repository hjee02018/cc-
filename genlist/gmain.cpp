#include <iostream>
#include "GenList.h"
using namespace std;

int main()
{
	GenList Inlist;
	//GenList inlist ���� 

	Inlist.Make(); 
	//���븮��Ʈ ����
	
	Inlist.Print();
	//���븮��Ʈ ���,xx
	
	while (1)
	{
		/*
		1 : Insert
		2 : Delete
		3 : Print
		4 : ����		
		*/

		// ��ɾ �����Լ� ����

		int select;
		cin >> select;
		// ����� ��ɾ �������� �Է¹���.

		char i, j;
		if (select == 1)
			// ��� i ��� �ڿ� j��带 ����
		{
			cin >> i >> j;
			Inlist.Insert(i, j);
		}

		else if (select == 2)
			// ��� i��� ����
		{
			cin >> i;
			Inlist.Delete(i);
		}

		else if (select == 3)
			// ���븮��Ʈ ���
		{
			Inlist.Print();
		}

		else if (select == 4)
			// ����
		
		{
			break;
		}

		else
			// ��ɾ� �Է¿���
		{
			cout << "Wrong Command" << endl;
		}

	}
}
