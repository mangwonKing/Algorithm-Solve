#include <bits/stdc++.h>
using namespace std;

int tree[52];
int n;
int m;
int leaf = 0;
void del(int d)
{
	tree[d] = -2;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] == d)
		{
			del(i);
		}
	}
}

void search(int now)
{
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] == now)
		{
			search(i);
			flag++;
		}
	}
	if (flag == 0)leaf++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >>tree[i];
	}
	cin >> m;
	if (tree[m] == -1)
	{
		cout << 0;
		return 0;
	}
	del(m);
	search(-1);
	cout << leaf;
}