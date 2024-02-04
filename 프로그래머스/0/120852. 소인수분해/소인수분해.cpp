#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	int i = 2;
	while (n > 1)
	{
		if (n % i == 0)
		{
			n /= i;
			answer.push_back(i);
		}
		else if (n % i != 0)
		{
			i++;
		}
	}
	set<int> temp;
	for (auto a : answer)
	{
		temp.insert(a);
	}
	answer.clear();
	for (auto a : temp)
	{
		answer.push_back(a);
	}
	//sort(answer.begin(), answer.end());
	return answer;
}