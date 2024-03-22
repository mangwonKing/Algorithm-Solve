#include <bits/stdc++.h>
using namespace std;

int n;
int board[12][12];
int vis[12][12];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int mn = INT_MAX;


bool check(int y,int x)
{
	if (vis[y][x])return false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)return false;
		if (vis[ny][nx])return false;
	}
	return true;
}
void go(int cnt, int total)
{
	if (cnt == 3)
	{
		mn = min(mn, total);
		return;
	}
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (!check(i, j))continue;
			vis[i][j] = 1;
			total += board[i][j];
			for (int a = 0; a < 4; a++)
			{
				int ny = i + dy[a];
				int nx = j + dx[a];
				vis[ny][nx] = 1;
				total += board[ny][nx];
			}
			go(cnt + 1, total);
			//원복
			vis[i][j] = 0;
			total -= board[i][j];
			for (int a = 0; a < 4; a++)
			{
				int ny = i + dy[a];
				int nx = j + dx[a];
				vis[ny][nx] = 0;
				total -= board[ny][nx];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >>n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	go(0, 0);
	cout << mn;
	return 0;
}