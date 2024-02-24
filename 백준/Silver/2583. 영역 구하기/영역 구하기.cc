#include <bits/stdc++.h>
using namespace std;

int paper[102][102];
int vis[102][102];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<int> area;
int m, n, k;

int dfs(int y , int x)
{
	vis[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n)continue;
		if (vis[ny][nx] == 1 || paper[ny][nx] == 1)continue;
		ret += dfs(ny, nx);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> m >> n >> k;
	for (int i = 0;i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				paper[y][x] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (paper[i][j] == 0 && vis[i][j] == 0)
			{
				area.push_back(dfs(i, j));
			}
		}
	}
	sort(area.begin(), area.end());
	cout << area.size() << "\n";
	for (auto a : area)
	{
		cout << a << " ";
	}
	
	return 0;
}