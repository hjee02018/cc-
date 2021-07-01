#ifndef POSTFIX_H
#define POSTFIX_H

// token types for non one-char tokens

#define ID 257
// 
#define NUM 258
//
#define EQ 259
//
#define NE 260
//
#define GE  261
//
#define LE 262
//
#define AND 263
// * operator
#define OR 264
// + operator
#define UMINUS 265
// unary minus
#define MAXLEN 80
// maxlength..?

struct Expression
{
	Expression(char* s) : str(s), pos(0)
	{
		for (len = 0; str[len] != '\0';len++);
	}
	char* str;
	int pos;
	int len;
};
// infix expression e -> postfix form¿∏∑Œ!!

struct  Token
{
	bool operator ==(char);
	bool operator !=(char);
	Token();
	Token(char);
	Token(char, char, int);
	Token(char*, int, int);
	bool IsOperand();
	int type;
	char* str;
	int len;
	int ival;
};
using namespace std;
ostream& operator<<(ostream&, Token);
Token NextToken(Expression&, bool);
#endif