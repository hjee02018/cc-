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

	cout << "[현재 상태 : " << getCurrentStateString() << "]" << endl;
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

// event 1 : 투입된 금액 출력
void StateMachine::displayInsertedMoney(int displayedMoneyAmount)
{
	cout << "현재 투입된 금액은" << displayedMoneyAmount << "원입니다." << endl;
}

// event 2 : 투입 금액 반환 
void StateMachine::refundCoins(int refunedMoneyAmount)
{
	cout << "반횐돠는 금액은" << refunedMoneyAmount << "원입니다." << endl;
}

// event 3 : 음료 버튼 조명 키거나/끄거나
void StateMachine::turnLight(int lightOn)
{
	if (lightOn == 1)
		cout << "음료 조명 키기" << endl;
	else
		cout << "음료 조명 끄기" << endl;
}

// event 4 : 음료 내보냄
void StateMachine::releaseBeverage(int dummy)
{
	cout << "음료 나왔습니다." << endl;
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