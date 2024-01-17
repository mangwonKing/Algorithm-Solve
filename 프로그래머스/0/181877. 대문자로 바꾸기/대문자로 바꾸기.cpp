#include <bits/stdc++.h>
using namespace std;

string solution(string myString) {
    string answer = "";
	int size = myString.size();

	for (int i = 0; i < size; i++)
	{
		char a = myString[i];
		if (a >= 'a' && a <= 'z')
		{
			a -= 'a';
			a += 'A';
			answer += a;
		}
		else
		{
			answer += a;
		}
	}

    return answer;
}