#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int h, w;
int area[102][102];
int dx = 1;
void search(int y , int x) //동쪽 방향 서치
{
	int nx = x + dx;
	if (nx < w && area[y][nx] < 0)
	{
		area[y][nx] = area[y][x] + 1;
		search(y, nx);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> h >> w;
	for (int i = 0; i < h; i++) //  맵 초기화
	{
		string s;
		cin >> s;
		for (int j = 0; j < w; j++)
		{
			if (s[j] == 'c')area[i][j] = 0;
			else area[i][j] = -1;

		}
	}
	
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (area[i][j] == 0)
			{
				search(i,j);
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << area[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}