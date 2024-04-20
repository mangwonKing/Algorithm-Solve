#include <bits/stdc++.h>

using namespace std;

int solution(int i, int j, int k) {
	int answer = 0;
	
	for (int a = i; a <= j; a++)
	{
		for (auto a : to_string(a))
		{
			if (a - '0' == k)answer++;
		}
	}
	return answer;
}