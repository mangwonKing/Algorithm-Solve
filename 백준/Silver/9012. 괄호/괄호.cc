#include <bits/stdc++.h>
using namespace std;

string ps;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	int t;
	cin >> t;
	
	while (t > 0)
	{
		t--;
		cin >> ps;
		stack<char> vps;
		for (auto s : ps)
		{
			if (vps.empty()) vps.push(s);
			else if (s == ')' && vps.top() == '(') vps.pop();
			else vps.push(s);
		}
		if (vps.size() == 0)cout << "YES\n";
		else cout << "NO\n";
	
	}
	return 0;
}