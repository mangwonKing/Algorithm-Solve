#include <bits/stdc++.h>
using namespace std;

int n;
int flag = 1;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;

	int x = 666;
	while (true)
	{
		if (flag == n) break;
		x++;
		int temp = x;
		int seq = 0;
		
		while (temp > 0)
		{
			if ((temp % 10) == 6)seq++;
			else if ((temp % 10) != 6) seq = 0;

			temp /= 10;

			if (seq == 3)
			{
				flag++;
				break;
			}
		}
	}

	cout << x;
	return 0;
}