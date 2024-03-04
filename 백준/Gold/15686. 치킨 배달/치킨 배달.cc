#include <bits/stdc++.h>
using namespace std;


int n, m;
int city[52][52];
vector < pair<int, int>> chiks;
vector < pair<int, int>> homes;
vector <vector<int>> chlist;
void combi(int start , vector<int> v)
{
	if (v.size() == m)
	{
		chlist.push_back(v);
		return;
	}
	for (int i = start + 1; i < chiks.size(); i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}
int dist = INT_MAX;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	//입력
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> city[i][j];
			if (city[i][j] == 1)homes.push_back({ i,j });
			else if (city[i][j] == 2)chiks.push_back({ i,j });
		}
	}

	// 가능한 치킨집의 조합을 구하기
	vector<int> v;
	combi(-1, v);
	// 조합을 하나씩 꺼내서 각 집별 가까운 치킨집의 거리 저장하고 최소값의 조합 찾기

	for (vector<int> ch : chlist)
	{
		int res = 0;
		for (pair<int, int> home : homes)
		{	
			int _min = INT_MAX;
			for (int idx : ch)
				_min = min(_min, abs(home.first - chiks[idx].first) + abs(home.second - chiks[idx].second));
			res += _min;
		}
		dist = min(dist, res);
	}
	cout << dist;
	
	return 0;
}