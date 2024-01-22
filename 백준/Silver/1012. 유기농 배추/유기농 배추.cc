#include <bits/stdc++.h>
using namespace std;

//페어를 편하게 쓰기 위한 매크로
#define X first
#define Y second

int board[51][51];
int vis[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int loop;
	cin >> loop;
	while (loop > 0)// 테스트 케이스만큼 돌기
	{
		
		int cnt = 0;//흰배추지렁이 마릿수
		queue<pair<int, int>> q;

		int n, m, k;// 배추밭 길이 와 위치개수

		cin >> n >> m >> k;
		int x, y; //좌표
		for (int i = 0; i < 50; i++)
		{
			fill(board[i], board[i] + 50, 0);
		}
		for (int i = 0; i < 50; i++)
		{

			fill(vis[i], vis[i] + 50, -1);// 방문기록 false 로 채우기
		}
		for (int i = 0; i < k; i++)//배추밭 채우기
		{
			cin >> x >> y;
			board[x][y] = 1;
		}
		
		//bfs 시작점 찾기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && vis[i][j]==-1)
				{
					q.push({ i,j });
					vis[i][j] = true;
					cnt++;
					while (!q.empty())//bfs 돌기
					{
						auto cur = q.front(); q.pop();
						for (int i = 0; i < 4; i++)
						{
							int nx = cur.X + dx[i];
							int ny = cur.Y + dy[i];
							if (nx < 0 || nx >= 50 || ny < 0 || ny >= 50)continue;
							if (vis[nx][ny] >= 0 || board[nx][ny] == 0)continue;
							q.push({ nx,ny });
							vis[nx][ny] = 0;
						}
					}
				}
			}
		}
		cout << cnt << "\n";
		loop--;
	}
	

	

	
}

