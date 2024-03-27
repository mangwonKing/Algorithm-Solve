#include <bits/stdc++.h>
using namespace std;


int d[6][3] =
{
	{9,3,1}, {9,1,3},{3,9,1},{3,1,9},{1,3,9},{1,9,3}
};
int vis[62][62][62];
int sc[62][62][62];
int a[3];
int n;

struct scv {
	int a, b, c;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sc[a[0]][a[1]][a[2]] = 1;
	vis[a[0]][a[1]][a[2]] = 1;
	queue<scv> q;
	q.push({ a[0],a[1],a[2] });
	while (!q.empty())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int na = a - d[i][0];
			int nb = b - d[i][1];
			int nc = c - d[i][2];
			if (na < 0) na = 0;
			if (nb < 0) nb = 0;
			if (nc < 0) nc = 0;
			if (na == 0 && nb == 0 && nc == 0)
			{
				cout << vis[a][b][c];
				return 0;
			}
			if (vis[na][nb][nc])continue;
			vis[na][nb][nc] = vis[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}
}