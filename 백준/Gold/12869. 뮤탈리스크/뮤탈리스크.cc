#include <bits/stdc++.h>
using namespace std;

int dam[6][3] =
{
	{9,3,1},{9,1,3},{3,9,1},{3,1,9},{1,9,3},{1,3,9}
};
int scv[62][62][62];
int vis[62][62][62];
int mn;
struct hp
{
	int a, b, c;
};
int n;
vector<int> f;

void bfs(int a, int b ,int c)
{
	queue<hp> q;
	q.push({ a,b,c });
	vis[a][b][c] = 1;
	while (!q.empty())
	{
		if (vis[0][0][0])
		{
			mn = vis[0][0][0]-1;
			return;
		}
		int x = q.front().a;
		int y = q.front().b;
		int z = q.front().c;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = max(0,x - dam[i][0]);
			int ny = max(0,y - dam[i][1]);
			int nz = max(0,z - dam[i][2]);
			
			if (vis[nx][ny][nz])continue;
			q.push({ nx,ny,nz });
			vis[nx][ny][nz] = vis[x][y][z] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		f.push_back(a);
	}
	while (f.size() < 3)
	{
		f.push_back(0);
	}
	bfs(f[0], f[1], f[2]);
	cout << mn;
	return 0;
}