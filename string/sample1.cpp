#include <iostream>
using namespace std;

int main()
{
	string input;
	int result = -1;
	cin >> input;
	for (int i = 0;i < input.size() - 2;i++)
	{
		if (input[i + 1] == input[i] && input[i + 2] == input[i])
			if (result < input[i]-48)
				result = input[i]-48;
	}
	cout << result << endl;
	return 0;
}
