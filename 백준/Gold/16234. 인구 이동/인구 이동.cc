#include <bits/stdc++.h>
using namespace std;

int country[52][52];
int n, l, r;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int vis[52][52];
vector<pair<pair<int, int>, int>> v; //좌표 - 값
void dfs(int y, int x )
{
	vis[y][x] = 1;
	v.push_back({ {y,x},country[y][x] });
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
		if (vis[ny][nx] == 1) continue;
		if (abs(country[ny][nx] - country[y][x]) < l ||
			abs(country[ny][nx] - country[y][x]) > r) continue;
		
		dfs(ny, nx);
	}

}
void moving()
{
	//벡터 전체의 넓이를 합하고 사이즈로 나눈 다음 좌표에 넣어주기
	int area = 0;
	for (auto vv : v)
	{
		area += vv.second;
	}
	area /= v.size();
	for (auto vv : v)
	{
		country[vv.first.first][vv.first.second] = area;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	//입력
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> country[i][j];
	}
	// 인구이동
	bool ismove = true; //인구이동이 진행되었는지
	int cnt = -1;
	while (ismove)
	{
		ismove = false;
		memset(vis, 0, sizeof(vis));
		cnt++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vis[i][j] == 0)
				{
					v.clear();
					dfs(i, j);
					if (v.size() > 1)
					{
						moving();
						ismove = true;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}