#include <bits/stdc++.h>
using namespace std;

int t;
long long n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	cin >> t;
	while (t > 0)
	{
		t--;
		cin >> n;
		int num2 = 0;
		int num5 = 0;
		int ret = 0;
		for (int i = 2; i <= n; i *= 2)
		{
			num2 += n  / i;
		}
		for (int i = 5; i <= n; i *= 5)
		{
			num5 += n / i;
		}
		ret = min(num2, num5);
		cout << ret << "\n";
	}
	return 0;
}