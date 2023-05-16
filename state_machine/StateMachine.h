#pragma once
#include <iostream>
// event-action table�� ���� entry ����
#define NUMBER_OF_TABLE_ENTRIES 100
// state transition�� ���� �Ǵ� �ִ� action ����
#define MAX_NUMBER_OF_ACTIONS 3

using namespace std;

// State ����
typedef enum {
	STATE_READY,
	STATE_100_INSERTED,
	STATE_200_INSERTED,
	STATE_END
}State;

// Event ����
typedef enum {
	EVENT_INSERT_100,
	EVENT_REFUND_BTN_PRESSED,
	EVENT_BEVERAGE_BTN_PRESSED,
	EVENT_QUIT
}Event;

class StateMachine
{
private:
	State curState;
	
	typedef struct {
		State curState;
		Event event;
		int num_of_actions;
		void(StateMachine::* action[MAX_NUMBER_OF_ACTIONS])(int);
		int action_parameter[MAX_NUMBER_OF_ACTIONS];
		State nextState;
	}EventActionTable;
	EventActionTable table[NUMBER_OF_TABLE_ENTRIES]
	{
		{STATE_READY,EVENT_INSERT_100,1,{&StateMachine::displayInsertedMoney},{100},STATE_100_INSERTED} ,
		{STATE_100_INSERTED, EVENT_INSERT_100, 2,  {&StateMachine::displayInsertedMoney, &StateMachine::turnLight},{200,1},STATE_200_INSERTED},
		{STATE_100_INSERTED, EVENT_REFUND_BTN_PRESSED,2,{&StateMachine::displayInsertedMoney,&StateMachine::refundCoins},{0,100},STATE_READY},
		{STATE_200_INSERTED, EVENT_INSERT_100,1, {&StateMachine::refundCoins},{100},STATE_200_INSERTED},
		{STATE_200_INSERTED, EVENT_REFUND_BTN_PRESSED,3, {&StateMachine::displayInsertedMoney,&StateMachine::refundCoins,&StateMachine::turnLight},{0,200,0},STATE_READY},
		{STATE_200_INSERTED,EVENT_BEVERAGE_BTN_PRESSED,3,{&StateMachine::displayInsertedMoney,&StateMachine::turnLight,&StateMachine::releaseBeverage},{0,0,0},STATE_READY}
	};

	// ȭ�鿡 ���� �ݾ� ǥ��
	void displayInsertedMoney(int displayedMoneyAmount);
	// ��ȯ��ư Ŭ�� �� ���Ե� �ݾ��� ��ȯ
	void refundCoins(int refundedMoneyAmount);
	// ���� ��ư ���� Ű�ų�/���ų�
	void turnLight(int lightOn);
	// ���� ������
	void releaseBeverage(int dummy);

	// ���� �̺�Ʈ�� �Է� ����
	Event getNextEvent();
	// ���� ���¿� �ش��ϴ� ���ڿ� �����Ͽ� ��ȯ
	string getCurrentStateString();

public:
	void run();
};



