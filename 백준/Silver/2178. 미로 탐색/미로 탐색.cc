#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int miro[104][104] = { 0 };
int visited[104][104] = { 0 };

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m;
	//map 그리기 1,1 ~ n,m
	for (int i = 1; i <= n; i++)
	{	
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{	
			if (s[j] == '1')miro[i][j+1] = 1;
		}
	}
	//bfs 1,1부터 시작
	queue<pair<int, int>> q;
	q.push({1,1});
	visited[1][1] = 1;
	while (q.size())
	{
		int y = q.front().first;
		int x = q.front().second;
		//cout << y << "," << x << "방문\n";
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 1 || ny > n || nx < 1 || nx > m)continue;
			if (miro[ny][nx] == 0)continue;
			if (visited[ny][nx] != 0)continue;
			q.push({ ny,nx });
			visited[ny][nx] = visited[y][x] + 1;

		}
	}
	cout << visited[n][m];
	return 0;
}