#include <string>
#include <vector>

using namespace std;
/*
3���� ��ȸ
0~10��
S,D,T
* : 2��, # : ���̳ʽ� <- ��ø ����
*/
int solution(string dartResult)
{
	int answer = 0;
	int N = dartResult.length();
	vector<int> scorelist;
	for (int i = 0;i < N;i++)
	{
		int score = 0;
		char res = dartResult[i];
		// ���� 
		if (res >= '0' && res <= '9')
		{
			if (dartResult[i + 1] == '0')
			{
				score = 10;
				i++;
			}
			else
				score = res - '0';

			i++;
			res = dartResult[i];
			if (res == 'S')
				score *= 1;
			else if (res == 'D')
				score = (score * score);
			else
				score = (score * score * score);

			if (dartResult[i + 1] == '*')
			{
				// �̹� score�� ���� score �� 2��
				if (!scorelist.empty())
					scorelist[scorelist.size()-1] *= 2;
				score *= 2;
				i++;
			}
			if (dartResult[i + 1] == '#')
			{
				score = (-1) * score;
				i++;
			}

			scorelist.push_back(score);
		}

	}

	for (int i = 0;i < 3;i++)
		answer += scorelist[i];

	return answer;
}

int main()
{
	solution("1S2D*3T");
}