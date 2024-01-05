#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str);
	int n, m;
	map<int, string> dogam1;
	map<string, int> dogam2;
	cin >> n >> m;
	//도감에 저장
	for (int i = 1; i <= n; i++)
	{
		string name;
		cin >> name;
		dogam1[i] = name;
		dogam2[name] = i;
	}
	//찾고자 하는 포켓몬 처리
	for (int i = 0; i < m; i++)
	{
		string order;
		int order2;
		cin >> order;
		if (order[0] >= '0' && order[0] <= '9')
		{
			order2 = stoi(order);
			cout << dogam1[order2]<<"\n";
		}
		else
		{
			cout << dogam2[order]<<"\n";
		}
	}
	return 0;
	
}