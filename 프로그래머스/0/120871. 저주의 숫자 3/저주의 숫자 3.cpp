#include <bits/stdc++.h>
using namespace std;


bool checkThree(int a) //3의 배수
{
	if (a % 3 == 0) return true;
	else return false;
}
bool checkThree2(int a)//3 포함여부
{
	string st = to_string(a);
	if (st.find("3") != string::npos)
		return true;
	return false;
}
int solution(int n) {
	int answer = 0;
	int k = 0;
	while(k < n)
	{
		answer++;
		if (checkThree(answer) || checkThree2(answer))continue;
		k++;
	}
	return answer;
}