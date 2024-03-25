#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int lad[34][34];
int mn = 5;
bool game()
{
	for (int i = 1; i <= n; i++)
	{
		int st = i;
		for (int j = 1; j <= h; j++)
		{
			if (lad[j][st])st++;
			else if (lad[j][st - 1])st--;
		}
		if (st != i) return false;
	}
	return true;
}

void solution(int row , int cnt)
{
	if (cnt > 3 || cnt >= mn)return;
	if (game())
	{
		mn = min(mn, cnt);
		return;
	}
	for (int i = row; i <= h; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (lad[i][j] || lad[i][j + 1] || lad[i][j - 1])continue;
			lad[i][j] = 1;
			solution(i, cnt + 1);
			lad[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		lad[a][b] = 1;
	}
	solution(1, 0);
	if (mn > 3) cout << -1;
	else cout << mn;
	return 0;
}