#include <string>
#include <vector>

using namespace std;
int solution(string my_string) {
	int answer = 0;
	vector<string> nums;
	string str;
	for (char a : my_string)
	{
		if (a >= '0' && a <= '9')
			str.push_back(a);
		else if (!str.empty())
		{
			nums.push_back(str);
			str.clear();
		}
	}
	if (!str.empty())
	{
		nums.push_back(str);
	}
	for (string st : nums)
	{
		answer += stoi(st);
	}
	return answer;
}