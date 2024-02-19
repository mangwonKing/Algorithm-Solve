#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int n, m;

int lab[10][10];

int wall = 3;
int mx = -1;

void go()
{
	if (wall == 0)
	{
		int cnt = 0;
		int visited[10][10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (lab[i][j] == 2)
				{
					queue<pair<int, int>> q;
					q.push({ i,j });
					visited[i][j] = 1;
					while (!q.empty())
					{
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							int ny = y + dy[k];
							int nx = x + dx[k];
							if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
							if (lab[ny][nx] == 1 || visited[ny][nx] == 1) continue;
							q.push({ ny,nx });
							visited[ny][nx] = 1;
						}
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (lab[i][j] != 1 && visited[i][j] == 0)cnt++; // 벽도 아니고 바이러스가 방문하지 않은 곳
			}
		}
		mx = max(mx, cnt);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (lab[i][j] == 0)
			{
				lab[i][j] = 1;
				wall--;
				go();
				lab[i][j] = 0;
				wall++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> lab[i][j];
		}
	}
	go();
	cout << mx;

	return 0;
}