#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기

	int n, m;
	int arr[15001] = { 0 };
	int cnt = 0;
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] + arr[j] == m)
			{
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
	
}