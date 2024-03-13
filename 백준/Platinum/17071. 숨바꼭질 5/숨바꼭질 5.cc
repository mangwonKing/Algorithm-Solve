#include <bits/stdc++.h>
using namespace std;

int sb, sis;
int vis[2][500002];
queue<int> q;
int sec = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> sb >> sis;
	if (sb == sis)
	{
		cout << 0;
		return 0;
	}
	vis[sec][sb] = 1;
	q.push(sb);
	while (q.size())
	{
		int size = q.size();
		sec++;
		sis += sec;
		if (sis > 500000)
			break;
		for (int i = 0; i < size; i++)
		{
			int x = q.front();
			q.pop();
			
			for (int next : {x - 1, x + 1, x * 2})
			{
				if (next >= 0 && next <= 500000)
				{
					if (vis[sec % 2][next])continue;
					vis[sec % 2][next] = 1;
					q.push(next);
					if (vis[sec % 2][sis])
					{
						cout << sec;
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}