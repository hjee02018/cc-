#include "StateMachine2.h"

void StateMachine::run()
{
	int i, j;
	Event curEvent;
	curState = INPUTING_OPERAND_1;

	while (curState != GETTING_OUTPUT)
	{
		curEvent = getNextEvent();
		for (int i = 0; i < NUM_OF_TABLE_ENTRIES; i++)
		{
			if (curState == table[i].curState)
			{
				if (curEvent == table[i].event)
				{
					(this->*table[i].action)(table[i].action_parameter);
					curState = table[i].nextState;
					break;
				}
			}
		}
		cout << endl << endl;
	}
}

string StateMachine::getCurrentStateString()
{
	string returnString;
	switch (curState)
	{
	case INPUTING_OPERAND_1:
		returnString = "INPUTING_OPERAND_1";
		break;
	case INPUTING_OPERATOR:
		returnString = "INPUTING_OPERATOR";
		break;
	case INPUTING_OPERAND_2:
		returnString = "INPUTING_OPERAND_2";
		break;
	case GETTING_OUTPUT:
		returnString = "GETTING_OUTPUT";
		break;

	}
	return returnString;
}

Event StateMachine::getNextEvent()
{
	Event selectedEvent;
	int inputEvent;

	cout << "[현재 상태 : " << getCurrentStateString() << "]" << endl;
	cout << "1. 숫자 입력" << endl;
	cout << "2. 연산자 입력" << endl;
	cout << "3. '='입력" << endl;
	cout << "Select an event # :";
	cin >> inputEvent;

	switch (inputEvent) {
	case 1:
		selectedEvent = EVENT_INPUT_NUM;
		break;
	case 2:
		selectedEvent = EVENT_INPUT_OP;
		break;
	case 3:
		selectedEvent = EVENT_INPUT_EQUAL;
		break;
	default:
		selectedEvent = EVENT_INPUT_NUM;
		curState = INPUTING_OPERAND_1;
	}
	return selectedEvent;
}


void StateMachine::displayInputValues(int dummy)
{
	cout << "입력된 값이 출력되었습니다." << endl;
}

void StateMachine::overwriteOperator(int dummy)
{
	cout << "입력된 연산자가 이전 연산자를 대체했습니다." << endl;
}

void StateMachine::eraseAlldisplayResult(int dummy)
{
	cout << "연산결과가 출력되었습니다." << endl;
}

void StateMachine::eraseAllDisplayDigit(int dummhy)
{
	cout << "이전 연산결과를 지우고 입력된 값이 출력되었습니다." << endl;
}