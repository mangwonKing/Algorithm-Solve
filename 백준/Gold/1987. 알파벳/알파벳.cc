#include <bits/stdc++.h>
using namespace std;


int r, c;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };
char board[21][21];
int vis[21][21];
int cn = 1;
vector<char> alpha;

void dfs(int y, int x,int cnt)
{

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= r || nx < 0 || nx >= c)continue;
		if (vis[ny][nx])continue;
		if (find(alpha.begin(), alpha.end(), board[ny][nx]) != alpha.end())continue;
		alpha.push_back(board[ny][nx]);
		vis[ny][nx] = cnt+1;
		cn = max(cn, vis[ny][nx]);
		dfs(ny, nx, cnt+1);
		vis[ny][nx] = 0;
		alpha.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
		}
	}
	vis[0][0] = 1;
	alpha.push_back(board[0][0]);
	dfs(0, 0,1);
	cout << cn;
	return 0;
}