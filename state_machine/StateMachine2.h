#pragma once
#include <iostream>
#define NUM_OF_TABLE_ENTRIES 100
using namespace std;

// State 정의
typedef enum
{
	INPUTING_OPERAND_1,
	INPUTING_OPERATOR,
	INPUTING_OPERAND_2,
	GETTING_OUTPUT
}State;

// Event 정의
typedef enum
{
	EVENT_INPUT_NUM,
	EVENT_INPUT_OP,
	EVENT_INPUT_EQUAL
}Event;

class StateMachine
{
private:
	State curState;
	typedef struct {
		State curState;
		Event event;
		void(StateMachine::* action)(int);
		int action_parameter;
		State nextState;
	}EventActionTable;
	EventActionTable table[NUM_OF_TABLE_ENTRIES]
	{
		{INPUTING_OPERAND_1,EVENT_INPUT_NUM,{&StateMachine::displayInputValues},{0},INPUTING_OPERAND_1},
		{INPUTING_OPERAND_1,EVENT_INPUT_OP,{&StateMachine::displayInputValues} ,{0},INPUTING_OPERATOR},
		{INPUTING_OPERATOR, EVENT_INPUT_NUM,{&StateMachine::displayInputValues},{0},INPUTING_OPERAND_2},
		{INPUTING_OPERATOR, EVENT_INPUT_OP,{&StateMachine::overwriteOperator},{0},INPUTING_OPERATOR},
		{INPUTING_OPERAND_2,EVENT_INPUT_NUM,{&StateMachine::displayInputValues},{0},INPUTING_OPERAND_2},
		{INPUTING_OPERAND_2,EVENT_INPUT_EQUAL,{&StateMachine::eraseAlldisplayResult},{0},GETTING_OUTPUT},
		{GETTING_OUTPUT,EVENT_INPUT_NUM,{&StateMachine::eraseAllDisplayDigit},{0},INPUTING_OPERAND_1}
	};
	void displayInputValues(int dummy);
	void overwriteOperator(int dummy);
	void eraseAlldisplayResult(int dummy);
	void eraseAllDisplayDigit(int dummy);

	// 다음 이벤트를 입력 받음
	Event getNextEvent();
	// 현재 상태에 해당하는 문자열 생성하여 반환
	string getCurrentStateString();

public:
	void run();

};