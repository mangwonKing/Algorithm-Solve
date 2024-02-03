#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
	string a = "aeiou";
	string answer = "";
	int flag;
	for (char s : my_string)
	{
		flag = 0;
		for (char w : a)
		{
			if (s == w)
			{
				flag = 1;
				continue;
			}
		}
		if (flag) continue;
		answer.push_back(s);
	}

	return answer;
}