// 5/22 1회차 다시풀기 성공 20분

#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	while (cin >> n)//입력이 끝나는 조건이 없을 때 입력받기
	{
		int idx = 1;
		int cnt = 1;
		while (true) 
		{
			idx = idx % n;
			if (idx == 0)break;
			cnt++;
			idx = idx *10 +1; // 자릿수 늘려가기
		}
		cout << cnt<<"\n";
	}
	return 0;
}
