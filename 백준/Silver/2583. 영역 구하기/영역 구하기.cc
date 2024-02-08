#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int paper[102][102] = { 0 };
int visited[102][102] = { 0 };

int n, m, k;

int dfs(int y, int x)
{
	visited[y][x] = 1;
	int area = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= m || nx < 0 || nx >= n)continue;
		if (paper[ny][nx] == 1 || visited[ny][nx] == 1)continue;
		area += dfs(ny, nx);
	}
	return area;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> m >> n >> k;
	vector<int>areas;
	int cnt = 0;
	for (int i = 0; i < k; i++)
	{
		int ax, ay, bx, by;
		cin >> ax >> ay >> bx >> by;
		for (int y = ay; y < by; y++)
		{
			for (int x = ax; x < bx; x++)
			{
				paper[y][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (paper[i][j] == 0 && visited[i][j] == 0)
			{
				areas.push_back(dfs(i,j));
				cnt++;
			}
		}
	}
	sort(areas.begin(), areas.end());
	cout << cnt << "\n";
	for (auto a : areas)
	{
		cout << a << " ";
	}
	return 0;
}