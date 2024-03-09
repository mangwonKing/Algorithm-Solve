#include <bits/stdc++.h>
using namespace std;


int vis[200002];
int cnt[200002];
int subin;
int sis;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> subin >> sis;
	if (subin == sis)
	{
		cout << 0 << "\n" << 1;
		return 0;
	}
	vis[subin] = 1;
	cnt[subin] = 1;
	queue<int> q;
	q.push(subin);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		for (int next : {x + 1, x - 1, x * 2})
		{
			if (next >= 0 && next <= 200000)
			{
				if (!vis[next])
				{
					q.push(next);
					vis[next] = vis[x] + 1;
					cnt[next] += cnt[x];
				}
				else if (vis[next] == vis[x] + 1)
				{
					cnt[next] += cnt[x];
				}
			}
		}
	}
	cout << vis[sis]-1 << "\n";
	cout << cnt[sis];
	return 0;
}