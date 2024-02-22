#include <bits/stdc++.h>
using namespace std;

int mx = -1;
vector<int> solution(vector<int> array) {
	vector<int> answer;
	for (int i = 0; i < array.size(); i++)
	{
		if (mx < array[i])
		{
			answer.clear();
			mx = array[i];
			answer.push_back(array[i]);
			answer.push_back(i);
		}
	}
	return answer;
}