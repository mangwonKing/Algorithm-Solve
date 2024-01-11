#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int cnt = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >>str;
		stack<char> s;

		for (auto e : str)
		{
			if (!s.empty() && s.top() == e)s.pop();
			else {
				s.push(e);
			}
		}
		if (s.empty()) cnt++;

	}
	cout << cnt;
}



