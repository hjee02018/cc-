#include <iostream>
#include <string>
#include "StateMachine.h"
using namespace std;



void StateMachine::run()
{
	int i, j;
	Event curEvent;
	curState = STATE_READY;

	while (curState != STATE_END)
	{
		curEvent = getNextEvent();
		for (int i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++)
		{
			if (curState == table[i].curState)
			{
				if (curEvent == table[i].event)
				{
					for (j = 0; j < table[i].num_of_actions; j++)
						(this->*table[i].action[j])(table[i].action_parameter[j]);
					curState = table[i].nextState;
					break;
				}
			}
		}
		cout << endl << endl;
	}
}

Event StateMachine::getNextEvent()
{
	Event selectedEvent;
	int inputEvent;

	cout << "[���� ���� : " << getCurrentStateString() << "]" << endl;
	cout << "1. Deposit a 100 won coint" << endl;
	cout << "2. Press the refund button" << endl;
	cout << "3. Press the beverage button you want" << endl;
	cout << "4. Quit" << endl;
	cout << "Select an event # :";
	cin >> inputEvent;

	switch (inputEvent) {
	case 1:
		selectedEvent = EVENT_INSERT_100;
		break;
	case 2:
		selectedEvent = EVENT_REFUND_BTN_PRESSED;
		break;
	case 3:
		selectedEvent = EVENT_BEVERAGE_BTN_PRESSED;
		break;
	case 4:
	default:
		selectedEvent = EVENT_QUIT;
		curState = STATE_END;
	}
	return selectedEvent;
}

// event 1 : ���Ե� �ݾ� ���
void StateMachine::displayInsertedMoney(int displayedMoneyAmount)
{
	cout << "���� ���Ե� �ݾ���" << displayedMoneyAmount << "���Դϴ�." << endl;
}

// event 2 : ���� �ݾ� ��ȯ 
void StateMachine::refundCoins(int refunedMoneyAmount)
{
	cout << "��Ⱥ�´� �ݾ���" << refunedMoneyAmount << "���Դϴ�." << endl;
}

// event 3 : ���� ��ư ���� Ű�ų�/���ų�
void StateMachine::turnLight(int lightOn)
{
	if (lightOn == 1)
		cout << "���� ���� Ű��" << endl;
	else
		cout << "���� ���� ����" << endl;
}

// event 4 : ���� ������
void StateMachine::releaseBeverage(int dummy)
{
	cout << "���� ���Խ��ϴ�." << endl;
}

string StateMachine::getCurrentStateString()
{
	string returnString;
	switch (curState)
	{
	case STATE_READY:
		returnString = "STATE_READY";
		break;
	case STATE_100_INSERTED:
		returnString = "STATE_100_INSERTED";
		break;
	case STATE_200_INSERTED:
		returnString = "STATE_200_INSERTED";
		break;
	}
	return returnString;
}