#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> quiz) {
	vector<string> answer;
	
	for (string s : quiz)
	{
		int left = 0;
		string temp;
		char del = 'x';
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '+')
			{
				del = '+';
				left += stoi(temp);
				temp.clear();
			}
			else if (s[i] == '-' && (s[i + 1] < '0' || s[i + 1] >'9'))
			{
				del = '-';
				left += stoi(temp);
				temp.clear();
			}
			else if (s[i] == '=')
			{
				if (del == '-')
				{
					left -= stoi(temp);
					temp.clear();
				}
				else
				{
					left += stoi(temp);
					temp.clear();
				}
			}
			else if(s[i] >= '0' && s[i] <= '9' )
			{
				temp.push_back(s[i]);
			}
			else if ((s[i] == '-' && (s[i + 1] >= '0' && s[i + 1] <='9')))
			{
				temp.push_back(s[i]);
			}
		}
		if (left == stoi(temp)) answer.push_back("O");
		else answer.push_back("X");
	}

	return answer;
}