#include <bits/stdc++.h>
using namespace std;
vector<string> num = { "zero", "one", "two", "three", "four",
"five", "six", "seven", "eight", "nine" };

long long  solution(string numbers) {
	string temp;
	long long answer = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		temp.push_back(numbers[i]);

		for (int j = 0; j < num.size(); j++)
		{
			if (num[j] == temp)
			{
				answer *= 10;
				answer += j;
				temp.clear();
				break;
			}
		}
	}
	
	return answer;
}