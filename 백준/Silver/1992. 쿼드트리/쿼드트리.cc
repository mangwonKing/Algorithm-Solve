#include <bits/stdc++.h>
using namespace std;


int qt[65][65];
int cnt[2];

bool ch(int x, int y, int n)
{
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (qt[x][y] != qt[i][j]) return false;
		}
	}
	return true;
}

void rec(int x, int y , int n)
{
	if (ch(x, y, n))
	{
		if (qt[x][y] == 0)
			cout << 0;
		else
			cout << 1;
		return;
	}
	
	n /= 2;
	if (n < 1)return;
	cout << "(";
	if(n>=1) {
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				rec(x + i * n, y + j * n, n);
			}
		}
	}
	cout << ")";
	
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
			char a;
			cin >> a;
			qt[i][j] = a - '0';
		}
	}
	rec(0, 0, n);

	return 0;

}

