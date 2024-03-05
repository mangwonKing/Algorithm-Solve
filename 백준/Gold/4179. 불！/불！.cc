#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int vis1[1002][1002]; //불 의 이동
int vis2[1002][1002]; //지훈이 의 이동
char miro[1002][1002];
pair<int, int> ji;
vector<pair<int, int>> fire;
int r, c;
int ext = -1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	//입력
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> miro[i][j];
			if (miro[i][j] == 'J') ji = { i,j };
			if (miro[i][j] == 'F') fire.push_back({ i,j });
		}
	}
	// 불 bfs
	queue<pair<int, int>>q;
	for (pair<int, int> idx : fire) //모든 불 위치로
	{
		q.push({ idx.first,idx.second });
		vis1[idx.first][idx.second] = 1;
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
			if (vis1[ny][nx] > 0 || miro[ny][nx] == '#')continue;
			q.push({ ny,nx });
			vis1[ny][nx] = vis1[y][x] + 1;
		}
	}
	// 지훈 bfs
	queue<pair<int, int>>q2;
	q2.push({ ji.first, ji.second });
	vis2[ji.first][ji.second] = 1;
	while (!q2.empty())
	{
		int y = q2.front().first;
		int x = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c)
			{
				cout << vis2[y][x];
				return 0;
			}
			if (vis2[ny][nx] > 0 || miro[ny][nx] == '#')continue;
			if (vis1[ny][nx] <= vis2[y][x] + 1 && vis1[ny][nx] != 0)continue;
			q2.push({ ny,nx });
			vis2[ny][nx] = vis2[y][x]+1;
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}