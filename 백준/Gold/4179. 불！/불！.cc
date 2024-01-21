#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1001] = {};
int dirF[1001][1001]; // 불의 이동
int dirJ[1001][1001]; // 지훈이의 이동

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 0; i < x; i++)
	{
		fill(dirF[i], dirF[i] + y, -1);
		fill(dirJ[i], dirJ[i] + y, -1);
		cin >> board[i];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{ 
			if (board[i][j] == 'F')
			{
				q1.push({ i,j });
				dirF[i][j] = 0;
			}
			if (board[i][j] == 'J')
			{
				q2.push({ i,j });
				dirJ[i][j] = 0;
			}
		}
	}

	while (!q1.empty())// 불의 이동을 기록
	{
		auto cur = q1.front(); 
		q1.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y)continue;
			if (board[nx][ny] == '#' || dirF[nx][ny] >= 0)continue;
			dirF[nx][ny] = dirF[cur.X][cur.Y] + 1;
			q1.push({ nx,ny });
		}
	}
	/*for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << dirF[i][j];
		}
		cout << "\n";
	}*/
	while (!q2.empty())// 지훈이 이동
	{
		auto cur = q2.front();
		q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			//탈출 성공 = 범위를 벗어났다는 것! 그러니 여기를
			//탈출로 처리하면 된다.,
			if (nx < 0 || nx >= x || ny < 0 || ny >= y)
			{
				cout << dirJ[cur.X][cur.Y]+1;// 마지막 이동횟수+
				return 0;
			}
			if (board[nx][ny] == '#' || dirJ[nx][ny] >= 0)continue;
			if (dirF[nx][ny] != -1&&dirF[nx][ny] <= dirJ[cur.X][cur.Y]+1)continue;//불이 먼저 와있는 경우 못지나감
			dirJ[nx][ny] = dirJ[cur.X][cur.Y] + 1;
			q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";// 위에서 리턴이 안되면 탈출을 못한것
	
}

