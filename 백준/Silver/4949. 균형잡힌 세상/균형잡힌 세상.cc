#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기

	string str;
	getline(cin, str);
	do
	{
		stack<char> balance;
		for (auto ch : str)
		{
			if (ch == '[' || ch == '(')balance.push(ch);
			else if (ch == ']')
			{
				if (!balance.empty() && balance.top() == '[') balance.pop();
				else balance.push(ch);
			}
			else if (ch == ')')
			{
				if (!balance.empty() && balance.top() == '(') balance.pop();
				else balance.push(ch);
			}
		}
		if (balance.empty())cout << "yes\n";
		else cout << "no\n";
		getline(cin, str);
	} while (str != ".");

	return 0;
}