#include <bits/stdc++.h>
using namespace std;

int n;
int coin[22];
int mn = INT_MAX;

void re(int here) //here = 행의 위치
{
	if (here == n)
	{
		int total = 0;
		for (int i = 1; i < (1 << n); i*=2)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
			{
				if (coin[j] & i)cnt++;
			}
			if (n - cnt < cnt) cnt = n - cnt;
			total += cnt;
		}
		mn = min(mn, total);
		//cout << mn << "이네용 " << "\n";
		return;
	}


	re(here + 1);
	coin[here] = ~coin[here];
	re(here + 1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'T') coin[i] |= value;
			value *= 2;
		}
	}
	re(0);
	cout << mn;
	return 0;
}