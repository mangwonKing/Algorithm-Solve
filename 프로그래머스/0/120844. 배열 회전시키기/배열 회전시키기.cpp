#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
	vector<int> answer;

	if (direction == "left")
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if ((i + 1) == numbers.size())
			{
				answer.push_back(numbers[0]);
			}
			else {
				answer.push_back(numbers[i+1]);
			}
		}
	}
	else
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if ((i - 1) < 0)
			{
				answer.push_back(numbers[numbers.size() - 1]);
			}
			else
			{
				answer.push_back(numbers[i-1]);
			}
		}
	}

	return answer;
}