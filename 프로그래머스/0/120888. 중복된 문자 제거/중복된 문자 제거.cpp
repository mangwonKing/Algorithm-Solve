#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
	string answer = "";
	
	for (auto a : my_string)
	{
		if (answer.find(a) == string::npos)
		{
			answer.push_back(a);
			cout << answer << endl;
		}
	}
	return answer;
}