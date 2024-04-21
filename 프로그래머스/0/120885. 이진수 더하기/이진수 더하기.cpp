#include <bits/stdc++.h>

using namespace std;

int toNum(string a)
{
	int n = a.size();
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '1')
		{
			int x = 1;
			for (int j = 0; j < n - i-1; j++)
				x *= 2;
			ret += x;
		}
	}
	return ret;
}
string solution(string bin1, string bin2) {
	string answer = "";
	int sum = toNum(bin1) + toNum(bin2);
	
	for (int i = 1; i <= sum; i *= 2)
	{
		if (i & sum)answer.push_back('1');
		else answer.push_back('0');
	}
	if (answer.size() == 0)return "0";
	reverse(answer.begin(),answer.end());
	return answer;
}