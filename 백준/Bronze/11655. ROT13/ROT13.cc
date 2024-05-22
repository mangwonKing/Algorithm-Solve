// 5/22 2회차 다시풀기 20분 성공
#include <bits/stdc++.h>
using namespace std;

string str;
string str2;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기 

	getline(cin, str);
	for (auto ch : str)
	{
		
		if (ch >= 'a' && ch <= 'z')
		{
			if (ch + 13 > 'z')ch = ch + 13 - 'z' + 'a'-1;
			else ch = ch + 13;
			str2.push_back(ch);
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			if (ch + 13 > 'Z')ch = ch + 13 - 'Z' + 'A'-1;
			else ch = ch + 13;
			str2.push_back(ch);
		}
		else str2.push_back(ch);
	}
	cout << str2;
	return 0;
}
