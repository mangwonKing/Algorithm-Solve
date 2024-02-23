#include <bits/stdc++.h>
using namespace std;

int n;
int num[1000004];
int ret[1000004];
stack<int> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		while (!s.empty() && num[s.top()] < num[i])
		{
			ret[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) cout << ret[i] << " ";
	return 0;
}