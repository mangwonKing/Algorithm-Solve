#include <bits/stdc++.h>
using namespace std;

int n, c;

map<int, int> code;
map<int, int> idx;

vector<pair<int, int>> v;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if (a.second == b.second)
	{
		return idx[a.first] < idx[b.first];
	}
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		code[a]++;
		if (idx[a] == 0)
		{
			idx[a] = i + 1;
		}
	}
	for (auto a : code)
	{
		//cout << a.first << " , " << a.second << endl;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto a : v)
	{
		for (int i = 0; i < a.second; i++)
			cout << a.first << " ";
	}
	return 0;
}