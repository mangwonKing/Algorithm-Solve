// 5/23 다시풀기 성공 , 기억하지 말고 생각해서 풀어보기 , 30분컷

#include <bits/stdc++.h>
using namespace std;

int n, k;
int vis[2][500002]; // 짝수,홀수 차례에 방문한 길 기록
int sec = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기 
	cin >> n >> k;
	if (n == k)
	{
		cout << 0;
		return 0;
	}
	queue<int> q;
	vis[0][n] = 1;// 수빈이 시작시점
	q.push(n); // 시작지점 q에 푸쉬
	while (1)
	{
		//1초 = 1레벨
		sec++;
		k += sec; //수빈이 위치 초만큼 +하기 
		if (k > 500000) break;
		int size = q.size();
		while (size--)// 한 레벨씩 진행
		{
			int now = q.front();
			q.pop();
			for (int next : {now + 1, now - 1, now * 2})
			{
				if (next > 500000 || next < 0) continue; // 0보다 작거나 50만보다 클 수 없다. 이걸 먼저 조사해야 out of bounds 를 피할 수 있다.
				if (vis[sec % 2][next])continue;//같은 홀 or 짝 에 방문한 적 있으면 continue
				q.push(next);
				vis[sec % 2][next] = 1;
				if (vis[sec % 2][k])// 동생이 방문할 지점을 같은 홀 or 짝에 수빈이가 방문을 이미 했다면 => 만날 수 있다.
				{
					cout << sec;
					return 0;
				}
			}
		}
	}
	cout << -1;// 찾지 못하고 while 을 나온 경우
	
	return 0;
}
