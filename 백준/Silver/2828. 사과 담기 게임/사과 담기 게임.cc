#include <bits/stdc++.h>
using namespace std;

int n, m;
int j; // 사과 개수
int screen[12] = { 0 };
int dis = 0;
int start;
int last;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m;
	for (int i = 1; i <= m; i++) //최초 왼쪽 m 칸 바구니 위치 
	{
		screen[i] = 1;
	}
	start = 1;
	last = m;
	cin >> j;
	while (j > 0) // 로직
	{
		j--;
		int cur;
		cin >> cur;
		if (screen[cur] == 1) continue;
		if (start > cur) // 바구니보다 왼쪽
		{
			dis += start - cur;
			for (int i = start; i <= last; i++)
			{
				screen[i] = 0;
			}
			start = cur;
			last = start + m - 1;
			for (int i = start; i <= last; i++)
			{
				screen[i] = 1;
			}
		}
		else if (last < cur) // 바구니보다 오른쪽
		{
			dis += cur - last;
			for (int i = start; i <= last; i++)
			{
				screen[i] = 0;
			}
			last = cur;
			start = cur - m + 1;
			for (int i = start; i <= last; i++)
			{
				screen[i] = 1;
			}
		}
		
	}
	cout << dis;
	return 0;
}