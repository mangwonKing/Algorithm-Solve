#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	int n;
	while (cin >> n)
	{
		int cnt = 1;
		int i = 1;
		while (i % n != 0)
		{
			i = (i * 10 + 1) % n;
			cnt++;
		}
		cout << cnt << "\n";
	}
	
	return 0;
}