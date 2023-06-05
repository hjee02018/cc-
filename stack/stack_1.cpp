#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
	bool isVps = true;
	int N;
	cin >> N;

	while (N > 0)
	{
		N--;
		string input;
		cin >> input;
		// 스택 생성
		stack<char> st;

		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == '(')
				st.push(input[i]);
			// ')'에 매칭되는 '('를 하나씩 pop
			else if (!st.empty() && input[i] == ')' && st.top() == '(')
				st.pop();
			// '('의 개수보다 ')'가 더 많이 등장한 경우
			else
			{
				isVps = false;
				break;
			}
		}
		// '('의 개수가 더 많은 경우
		if (!st.empty()) isVps = false;

		if (isVps)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}