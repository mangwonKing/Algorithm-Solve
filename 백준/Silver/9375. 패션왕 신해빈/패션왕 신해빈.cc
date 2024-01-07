#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	int n, m;
	cin >> n;

	while (n--)
	{
		map<string, int> cloth;
		cin >> m;
		while (m--)
		{
			string name;
			string category;
			cin >> name >> category;
			cloth[category]++;
		}
		int ret = 1;
		for (auto a : cloth)
		{
			a.second++;
			ret *= a.second;
		}
		ret--;
		cout << ret<<"\n";
	}
	return 0;
	
}