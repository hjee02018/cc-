#include <iostream>
#include <stack>
#include "post.h"
using namespace std;

bool Token::operator==(char b)
{
	return len == 1 && str[0] == b;
}
// len값이 1이며, str[0]에 저장된 문자가 'b'이면 참반환

bool Token::operator!=(char b)
{
	return len != 1 || str[0] != b;
}
// len값이 1이 아니거나, str[0]에 저장된 문자가 'b'가 아니면 반환

Token::Token(){}

Token::Token(char c) :len(1), type(c)
{
	str = new char[1];
	str[0]= c;
} //default type = c itself
 // 길이가 1 인 연산자 혹은 피연산자

Token::Token(char c, char c2, int ty) : len(2), type(ty)
{
	str = new char[2];
	str[0] = c;
	str[1] = c2;
}
// 길이가 2인 연산자
Token::Token(char* arr, int l, int ty = ID) : len(l), type(ty)
{
	str = new char[len + 1];
	for (int i = 0;i < len;i++)
	{
		str[i] = arr[i];
	}
		str[len] = '\n';
		if (type == NUM)
		{
			ival = arr[0] = '0';
			for (int i = 1;i < len;i++)
			{
				ival = ival * 10 + arr[i] - '0';
			}
		}
		else if (type == ID) ival = 0;
		else throw "must be ID or NUM";
}
// 피연산자 길이가 2 이상일때,

bool Token::IsOperand()
{
	return type == ID || type == NUM;
}
// 피연산자인가?


ostream& operator<<(ostream& os, Token t)
{
	if (t.type == UMINUS) os << "-u";
	else if (t.type == NUM) os << t.ival;
	else for (int i = 0;i < t.len;i++) os << t.str[i];
	os << " ";
	return os;
}
bool GetID(Expression& e, Token& tok)
{
	char arr[MAXLEN];
	int idlen = 0;
	char c = e.str[e.pos];
	if (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'))return false;
	// 알파벳이 아니면 거짓을 반환

	arr[idlen++] = c;
	//배열에 저장

	e.pos++;
	while ((c = e.str[e.pos]) >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
	// c 에는 이제 다음문자저장, 
	// 다음문자가 알파벵시거나 숫자인 경우에만 
	{
		arr[idlen++] = c;
		e.pos++;
	}
	arr[idlen] = '\n';
	// 문자열의 마지막은 개행

	tok = Token(arr, idlen, ID);
	return true;
}

bool GetInt(Expression& e, Token& tok)
{
	// 작성
	char arr[MAXLEN];
	int len = 0;
	char c = e.str[e.pos];
	if (!(c >= '0' && c <= '9'))
		return false;
	// 숫자가 아니면 거짓
	arr[len++] = c;
	e.pos++;
	while ((c = e.str[e.pos]) >= '0' && c <= '9')
	// 숫자일 경우에만
	{
		arr[len++] = c;
		e.pos++;
	}
	arr[len] = '\n';
	tok = Token(arr, len);
	return true;


}

void SkipBlanks(Expression& e)
// 공백을 넘어가는 함수
{
	char c;
	while (e.pos < e.len && ((c = e.str[e.pos]) == ' ' || c == '\t'))
		e.pos++;
}

bool TwoCharOp(Expression& e, Token& tok)
// 길이가 2인 연산자
// 7가지 두글자 토큰들 <= >= == != && || -u를 처리
{
	char c = e.str[e.pos];
	char c2 = e.str[e.pos + 1];
	int op;
	if (c == '<' && c2 == '=') op = LE;
	else if (c == '>' && c2 == '=')
	{
		op = GE;
	}
	else if (c == '=' && c2 == '=')
	{
		op = EQ;
	}
	else if (c == '!' && c2 == '=')
	{
		op = NE;
	}
	else if (c == '&' && c2 == '&')
	{
		op == AND;
	}
	else if (c == '|' && c2 == '|')
	{
		op = OR;
	}
	else if (c == '~' && c2 == 'u')
	{
		op = UMINUS;
	}

	// .각 두글자 토큰에 대해 알맞은 type값을 op에 저장
	else return false; // 맞는 두글자 토큰이 아니면 false를 return

	tok = Token(c, c2, op);
	e.pos += 2;
	return true;
}

bool OneCharOp(Expression& e, Token& tok)
// 길이가 1 인 연산자
{
	char c = e.str[e.pos];
	if (c == '-' || c == '!' || c == '*' || c == '/' || c == '%' || c == '+' || c == '<' || c == '>' || c == '(' || c == ')' || c == '=')
	{
		tok = Token(c);
		e.pos++;
		return true;
	}
	return false;
}

Token NextToken(Expression& e)
// 다음 토큰을 반환하는 함수
{
	static bool oprrFound = true;
	//종전에 연산자 발견되었다고 가정.

	Token tok;

	SkipBlanks(e);
	if (e.pos == e.len)
		//no more token left in this expression
	{
		return Token('#');
	}

	if (GetID(e, tok) || GetInt(e, tok))
		// 피연산자의 경우
	{
		return tok;
	}

	if (TwoCharOp(e, tok) || OneCharOp(e, tok))
		// 연산자의 경우
	{
		if (tok.type == '-' && e.str[e.pos - 2] == '-')
			//operator후 -발견
		{
			tok = Token('-', 'u', UMINUS);
			// unary minus(-u)로 바꾸시오
		}
		return tok;
	}
	throw "Illegal Character Found";
}

int icp(Token& t)
// incoming prioty 
{
	
	int ty = t.type;

	if (t.type == '(')
		return 0;
	else if (t.type == UMINUS || t.type == '!')
		return 1;
	else if (t.type == '*' || t.type == '/' || t.type == '%')
		return 2;
	else if (t.type == '+' || t.type == '-')
		return 3;
	else if (t.type == '<' || t.type == '>' || t.type == LE || t.type == GE)
		return 4;
	else if (t.type == EQ || t.type == NE)
		return 5;
	else if (t.type == AND)
		return 6;
	else if (t.type == OR)
		return 7;
	else if (t.type == '#')
		return 9;
	/*
	ty가 '('면 0, UMINUS나 '!면 1,
	'*'나 '/'나 '%'면 2,
	'+'나 '-'면 3,
	'<'나 '>'나 LE나 GE면 4,
	EQ나 NE면 5,
	AND면 6,
	OR이면,7,
	'='이면 8,
	'#'면 9를 return 한다.
	*/
}

int isp(Token& t)
// stack에서의 우선순위 결정
{
	int ty = t.type;
	if (t.type == '(')
		return 9;
	else if (t.type == UMINUS || t.type == '!')
		return 1;
	else if (t.type == '*' || t.type == '/' || t.type == '%')
		return 2;
	else if (t.type == '+' || t.type == '-')
		return 3;
	else if (t.type == '<' || t.type == '>' || t.type == LE || t.type == GE)
		return 4;
	else if (t.type == EQ || t.type == NE)
		return 5;
	else if (t.type == AND)
		return 6;
	else if (t.type == OR)
		return 7;
	else if (t.type == '=')
		return 9;
}

void Postfix(Expression e)
{
	// infix expression e를 postfix form으로 바꾸어 출력
	// e에 토큰이 없으면 NextToken은 '#' 토큰을 변환한다.
	// 스택의 밑에도 '#'를 넣고 시작한다.
	
	stack <Token> hjstack;
	// hjstack이란 이름의 stack생성

	hjstack.push('#');
	//스택의 밑에 '#'을 넣고 시작

	for (Token x = NextToken(e);x != '#';x = NextToken(e))
	// 마지막 토큰 '#' 이 올 때까지 for문 실행
	{
		if (x.IsOperand())
			cout << x;
		// 피연산자라면 출력

		else if (x == ')')
		// 괄호 처리 코드
		{
			for (;hjstack.top() != '(';hjstack.pop())
				cout << hjstack.top();
			hjstack.pop();
		}
		
		else
		// 연산자들간 우선순위 비교
		{
			for (;isp(hjstack.top()) <= icp(x);hjstack.pop())
			// 앞에 들어올 연산자의 prioty <= 현재 연산자의 prioty
				//-> 출력 후 pop
			{
				cout << hjstack.top();
			}
			hjstack.push(x);
			// 다음 연산자 삽입
		}

	}

	while (hjstack.top() != '#') 

	{

		cout << hjstack.top();

		hjstack.pop();

	}

	cout << endl;

}