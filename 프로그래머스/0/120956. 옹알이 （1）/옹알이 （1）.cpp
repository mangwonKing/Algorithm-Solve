#include <bits/stdc++.h>

using namespace std;

string word[4] = { "aya","ye","woo","ma" };
int solution(vector<string> babbling) {
	int answer = 0;
	for (string bab : babbling)
	{
		int size = 0;
		for (int i = 0; i < 4; i++)
			if (bab.find(word[i]) != string::npos)
				size += word[i].size();
		if (bab.size() == size)answer++;
	}
	return answer;
}