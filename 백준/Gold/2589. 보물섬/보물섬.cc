#include <bits/stdc++.h>
using namespace std;


int n, m;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int island[52][52];
int vis[52][52];
int maxDist = INT_MIN;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			if (a == 'W')island[i][j] = 1; //1 은 바다
			else island[i][j] = 0; // 0 은 육지
		}
	}
	//전체 돌면서 bfs 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (island[i][j] == 0)
			{
				int dis = 0;
				memset(vis, 0, sizeof(vis));
				queue < pair<int, int>> q;
				q.push({ i,j });
				vis[i][j] = 1;
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
						if (island[ny][nx] == 1 || vis[ny][nx] != 0)continue;
						vis[ny][nx] = vis[y][x] +1;
						q.push({ ny,nx });
					}
					if (q.empty()) {
						dis = vis[y][x]-1;
						break;
					}
				}
				maxDist = max(maxDist, dis);
			}
		}
	}
	cout << maxDist;
	return 0;
}