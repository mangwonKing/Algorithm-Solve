#include <bits/stdc++.h>
using namespace std;

int r,c,k;
string way[7];
int vis[7][7];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int cnt = 0;
void dfs(int y, int x, int dist)
{
	if (y == 0 && x == c - 1)
	{
		if (dist == k)cnt++;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
		if (vis[ny][nx]|| way[ny][nx] == 'T')continue;
		vis[ny][nx] = 1;
		dfs(ny, nx, dist + 1);
		vis[ny][nx] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		cin >> way[i];
	}
	vis[r - 1][0] = 1;
	dfs(r - 1, 0,1);
	cout << cnt;
	return 0;
}