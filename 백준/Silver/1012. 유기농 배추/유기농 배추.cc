#include <bits/stdc++.h>
using namespace std;
 
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int miro[52][52];
int visited[52][52];
int n, m, num;

void dfs(int y , int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (miro[ny][nx] == 0) continue;
		if (visited[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	int loop;
	cin >> loop;
	while (loop)
	{
		
		int cnt = 0;
		loop--;
		cin >> m >> n >> num; 
		//미로 초기화
		for (int i = 0; i < 52; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				miro[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		int x = 0;
		int y = 0;
		for (int i = 0; i < num; i++)
		{
			
			cin >> x >> y;
			miro[y][x] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (miro[i][j] == 1 && visited[i][j] == 0)
				{
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt<<"\n";
	}
	return 0;
}