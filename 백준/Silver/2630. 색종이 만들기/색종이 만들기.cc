#include <bits/stdc++.h>
using namespace std;



int pa[130][130];
int cnt[2];

bool ch(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (pa[x][y] != pa[i][j])
				return false;
		}
	}
	return true;
}

void rec(int x, int y , int n)
{
	if (ch(x, y, n))//종이가 같은수면
	{
		cnt[pa[x][y]] += 1;
		return;
	}
	else//같지 않은 수로 섞이면 분할
	{
		int z = n / 2;
		for(int i = 0 ; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				rec(x + i * z, y + j * z, z);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> pa[i][j];
		}
	}
	rec(0, 0, n);

	cout << cnt[0] << "\n";
	cout << cnt[1] << "\n";
	return 0;

}

