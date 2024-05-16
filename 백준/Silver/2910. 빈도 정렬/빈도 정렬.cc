// 5-16 2회차 7일 후 다시풀기 완벽 성공 (15분컷, 코드 더 간결) 
#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> msg;
map<int, int> idx; // 빈도가 같을경우 등장한 순서를 기록하기 위한 map
vector<pair<int, int>> deco; // 커스텀 정렬을 위해 map 저장할 그릇

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)return idx[a.first] < idx[b.first];
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		msg[a]++;
		if (idx[a] == 0)
			idx[a] = i + 1;
	}
	for (auto a : msg)
		deco.push_back(a);
	sort(deco.begin(), deco.end(), cmp);
	for (auto a : deco)
		for (int i = 0; i < a.second; i++)
			cout << a.first << " ";

	return 0;
}
