#include <bits/stdc++.h>
using namespace std;

//페어를 편하게 쓰기 위한 매크로
#define X first
#define Y second

string board[31][31]; //30층 30x30 건물
int dis[31][31][31];// 거리측정

int dx[6] = {1 ,0 ,0,-1, 0 ,0};
int dy[6] = {0 ,1 ,0,0 ,-1 ,0};
int dz[6] = {0 ,0 ,1,0 , 0 ,-1 };

int main(void) {                  
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true)
	{
		
		int l, r, c;
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)return 0;

		queue<pair<pair<int, int>, int>> q;

		for (int i = 0; i < l; i++)
		{
			
			for (int j = 0; j < r; j++)
			{
				cin >> board[i][j];
				for (int k = 0; k < c; k++)
				{
					/*char a;
					cin >> a;
					board[i][j][k] = a;*/
					if (board[i][j][k] == 'S')
					{
						q.push({ {j,k},i });
						dis[i][j][k] = 0;
					}
					else
					{
						dis[i][j][k] = -1;
					}
				}
			}
		}
		bool esc = false;
		int tim;
		while (!q.empty())//bfs
		{
			auto cur = q.front(); //[x,y][z]
			q.pop();

			//board[z][x][y] 
			for (int idx = 0; idx < 6; idx++)
			{
				int nx = dx[idx] + cur.X.X; //x
				int ny = dy[idx] + cur.X.Y; //y
				int nz = dz[idx] + cur.Y; //z


				if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l)continue;
				if (board[nz][nx][ny] == 'E')
				{
					esc = true;
					tim = dis[cur.Y][cur.X.X][cur.X.Y] + 1;
					break;
				}
				if (board[nz][nx][ny] == '#' || dis[nz][nx][ny] != -1)continue;
				q.push({ { nx,ny }, nz });
				dis[nz][nx][ny] = dis[cur.Y][cur.X.X][cur.X.Y] + 1;
			}
		}
		if (esc)cout << "Escaped in " << tim << " minute(s).\n";
		else cout << "Trapped!\n";
	}
	return 0;
	
}

