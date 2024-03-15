#include <bits/stdc++.h>
using namespace std;

int n, m;
int a1, b1, a2, b2;
char room[302][302];
int vis[302][302];
int jump = 0;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
queue<pair<int,int>>q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m;
	cin >> a1 >> b1 >> a2 >> b2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}
	vis[a1 - 1][b1 - 1] = 1;
	q.push({ a1 - 1,b1 - 1 });
	while (!q.empty())
	{
		
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
			if (vis[ny][nx])continue;
			
			//q.push({ ny,nx });
			vis[ny][nx] = vis[y][x] + 1;
			if (room[ny][nx] == '#')
			{
				cout << vis[ny][nx]-1;
				return 0;
			}
			if (room[ny][nx] == '1')
			{
				q.push({ ny,nx });
			}
			else
			{
				queue<pair<int, int>> q2;
				q2.push({ ny, nx });
				while (!q2.empty())
				{
					int nny = q2.front().first;
					int nnx = q2.front().second;
					q2.pop();
					for (int j = 0; j < 4; j++)
					{
						int nnny = nny + dy[j];
						int nnnx = nnx + dx[j];
						if (nnny < 0 || nnny >= n || nnnx < 0 || nnnx >= m)continue;
						if (vis[nnny][nnnx])continue;
						vis[nnny][nnnx] = vis[nny][nnx];
						if (room[nnny][nnnx] == '#')
						{
							cout << vis[nnny][nnnx]-1;
							return 0;
						}
						if (room[nnny][nnnx] == '1')q.push({ nnny,nnnx });
						else q2.push({ nnny,nnnx });
					}
				}
			}
		}
	}
	return 0;
}