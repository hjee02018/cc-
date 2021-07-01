#include <iostream>
#include <stack>
#include "post.h"
using namespace std;

bool Token::operator==(char b)
{
	return len == 1 && str[0] == b;
}
// len���� 1�̸�, str[0]�� ����� ���ڰ� 'b'�̸� ����ȯ

bool Token::operator!=(char b)
{
	return len != 1 || str[0] != b;
}
// len���� 1�� �ƴϰų�, str[0]�� ����� ���ڰ� 'b'�� �ƴϸ� ��ȯ

Token::Token(){}

Token::Token(char c) :len(1), type(c)
{
	str = new char[1];
	str[0]= c;
} //default type = c itself
 // ���̰� 1 �� ������ Ȥ�� �ǿ�����

Token::Token(char c, char c2, int ty) : len(2), type(ty)
{
	str = new char[2];
	str[0] = c;
	str[1] = c2;
}
// ���̰� 2�� ������
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
// �ǿ����� ���̰� 2 �̻��϶�,

bool Token::IsOperand()
{
	return type == ID || type == NUM;
}
// �ǿ������ΰ�?


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
	// ���ĺ��� �ƴϸ� ������ ��ȯ

	arr[idlen++] = c;
	//�迭�� ����

	e.pos++;
	while ((c = e.str[e.pos]) >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
	// c ���� ���� ������������, 
	// �������ڰ� ���ĺ��ðų� ������ ��쿡�� 
	{
		arr[idlen++] = c;
		e.pos++;
	}
	arr[idlen] = '\n';
	// ���ڿ��� �������� ����

	tok = Token(arr, idlen, ID);
	return true;
}

bool GetInt(Expression& e, Token& tok)
{
	// �ۼ�
	char arr[MAXLEN];
	int len = 0;
	char c = e.str[e.pos];
	if (!(c >= '0' && c <= '9'))
		return false;
	// ���ڰ� �ƴϸ� ����
	arr[len++] = c;
	e.pos++;
	while ((c = e.str[e.pos]) >= '0' && c <= '9')
	// ������ ��쿡��
	{
		arr[len++] = c;
		e.pos++;
	}
	arr[len] = '\n';
	tok = Token(arr, len);
	return true;


}

void SkipBlanks(Expression& e)
// ������ �Ѿ�� �Լ�
{
	char c;
	while (e.pos < e.len && ((c = e.str[e.pos]) == ' ' || c == '\t'))
		e.pos++;
}

bool TwoCharOp(Expression& e, Token& tok)
// ���̰� 2�� ������
// 7���� �α��� ��ū�� <= >= == != && || -u�� ó��
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

	// .�� �α��� ��ū�� ���� �˸��� type���� op�� ����
	else return false; // �´� �α��� ��ū�� �ƴϸ� false�� return

	tok = Token(c, c2, op);
	e.pos += 2;
	return true;
}

bool OneCharOp(Expression& e, Token& tok)
// ���̰� 1 �� ������
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
// ���� ��ū�� ��ȯ�ϴ� �Լ�
{
	static bool oprrFound = true;
	//������ ������ �߰ߵǾ��ٰ� ����.

	Token tok;

	SkipBlanks(e);
	if (e.pos == e.len)
		//no more token left in this expression
	{
		return Token('#');
	}

	if (GetID(e, tok) || GetInt(e, tok))
		// �ǿ������� ���
	{
		return tok;
	}

	if (TwoCharOp(e, tok) || OneCharOp(e, tok))
		// �������� ���
	{
		if (tok.type == '-' && e.str[e.pos - 2] == '-')
			//operator�� -�߰�
		{
			tok = Token('-', 'u', UMINUS);
			// unary minus(-u)�� �ٲٽÿ�
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
	ty�� '('�� 0, UMINUS�� '!�� 1,
	'*'�� '/'�� '%'�� 2,
	'+'�� '-'�� 3,
	'<'�� '>'�� LE�� GE�� 4,
	EQ�� NE�� 5,
	AND�� 6,
	OR�̸�,7,
	'='�̸� 8,
	'#'�� 9�� return �Ѵ�.
	*/
}

int isp(Token& t)
// stack������ �켱���� ����
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
	// infix expression e�� postfix form���� �ٲپ� ���
	// e�� ��ū�� ������ NextToken�� '#' ��ū�� ��ȯ�Ѵ�.
	// ������ �ؿ��� '#'�� �ְ� �����Ѵ�.
	
	stack <Token> hjstack;
	// hjstack�̶� �̸��� stack����

	hjstack.push('#');
	//������ �ؿ� '#'�� �ְ� ����

	for (Token x = NextToken(e);x != '#';x = NextToken(e))
	// ������ ��ū '#' �� �� ������ for�� ����
	{
		if (x.IsOperand())
			cout << x;
		// �ǿ����ڶ�� ���

		else if (x == ')')
		// ��ȣ ó�� �ڵ�
		{
			for (;hjstack.top() != '(';hjstack.pop())
				cout << hjstack.top();
			hjstack.pop();
		}
		
		else
		// �����ڵ鰣 �켱���� ��
		{
			for (;isp(hjstack.top()) <= icp(x);hjstack.pop())
			// �տ� ���� �������� prioty <= ���� �������� prioty
				//-> ��� �� pop
			{
				cout << hjstack.top();
			}
			hjstack.push(x);
			// ���� ������ ����
		}

	}

	while (hjstack.top() != '#') 

	{

		cout << hjstack.top();

		hjstack.pop();

	}

	cout << endl;

}