#include <bits/stdc++.h>
using namespace std;

int main() {
	//getline(cin, str);
	int n;
	string pattern;
	cin >> n;
	cin >> pattern;
	//패턴 처리
	int len = pattern.size() - 1;
	
	//문자열 입력 및 패턴 비교
	for (int i = 0; i < n; i++)
	{	
		bool flag = true;
		string name;
		cin >> name;
		if (len > name.size()) {
			cout << "NE\n";
			continue;
		}
		for (int i = 0; i < name.size(); i++)
		{
			if (pattern[i] == '*')break;
			if (pattern[i] != name[i]) {
				flag = false;
				cout << "NE\n";
				break;
			}
		}
		if (flag == false) continue;
		for (int i = 1; i <= name.size(); i++)
		{
			if (pattern[pattern.size()-i] == '*')break;
			if (pattern[pattern.size() - i] != name[name.size()-i]) {
				flag = false;
				cout << "NE\n";
				break;
			}
		}
		if (flag)cout << "DA\n";
	}
	
	return 0;
	
}