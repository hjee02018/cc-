#pragma once
#include <iostream>
// event-action table의 현재 entry 개수
#define NUMBER_OF_TABLE_ENTRIES 100
// state transition시 실행 되는 최대 action 개수
#define MAX_NUMBER_OF_ACTIONS 3

using namespace std;

// State 정의
typedef enum {
	STATE_READY,
	STATE_100_INSERTED,
	STATE_200_INSERTED,
	STATE_END
}State;

// Event 정의
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

	// 화면에 투입 금액 표시
	void displayInsertedMoney(int displayedMoneyAmount);
	// 반환버튼 클릭 시 투입된 금액을 반환
	void refundCoins(int refundedMoneyAmount);
	// 음료 버튼 조명 키거나/끄거나
	void turnLight(int lightOn);
	// 음료 내보냄
	void releaseBeverage(int dummy);

	// 다음 이벤트를 입력 받음
	Event getNextEvent();
	// 현재 상태에 해당하는 문자열 생성하여 반환
	string getCurrentStateString();

public:
	void run();
};



