#include <bits/stdc++.h>

using namespace std;
int solution(string before, string after) {
	int answer = 0;
	
	for (int i = 0; i < before.size(); i++)
	{
		if (find(after.begin(), after.end(), before[i]) != after.end())
		{
			after.erase(find(after.begin(), after.end(), before[i]));
		}
	}
	if (after.size())return 0;
	return 1;
}