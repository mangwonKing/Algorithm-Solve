#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	int n;
	while (cin >> n)
	{
		
		ll i = 10;
		ll a = 1;
		int cnt = 1;
		while (true)
		{
			if (a % n == 0)break;
			a = (a * 10 + 1);
			a %= n;
			cnt++;
		}
		cout << cnt<<"\n";
	}
	
	return 0;
	
}