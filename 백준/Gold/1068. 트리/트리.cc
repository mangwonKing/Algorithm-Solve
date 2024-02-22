#include <bits/stdc++.h>
using namespace std;

int tree[52];
int n;
int del;
int leaf = 0;
void delsub(int parent)
{
	for (int i = 0; i < n; i++)
	{
		if (tree[i] == parent)
		{
			tree[i] = -2;
			delsub(i);
		}
	}
}

void search(int parent)
{
	bool find = false;
	for (int i = 0; i < n; i++)
	{
		if (tree[i] == parent)
		{
			find = true;
			search(i);
		}
	}
	if (!find ) leaf++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i <  n ;i++)
	{
		cin >> tree[i];
	}
	cin >> del;
	if (tree[del] == -1) //루트노드를 바로 지운 경우
	{
		cout << leaf;
		return 0;
	}
	tree[del] = -2;
	delsub(del);
	search(-1);
	cout<< leaf;
	return 0;
}