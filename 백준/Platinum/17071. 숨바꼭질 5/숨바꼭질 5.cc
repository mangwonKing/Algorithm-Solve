// 5/20 다시풀기 실패 시간주기관리 및 bfs를 활용한 flood fill 떠올리기, 3일 뒤 다시하기

#include <bits/stdc++.h>
using namespace std;

int sb, sis;
int vis[2][500002];// 홀 수 짝 수
queue<int> q;
int sec = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> sb>> sis;
	if (sb == sis)
	{
		cout << 0;
		return 0;
	}
	vis[sec][sb] = 1; //수빈이 이동
	q.push(sb);
	while (q.size()) 
	{
		int size = q.size();
		sec++;
		sis += sec; //동생과 같은 레벨로 실행
		if (sis > 500000)
			break;
		for (int i = 0; i < size; i++)
		{
			int x = q.front();
			q.pop();

			for (int next : {x - 1, x + 1, x * 2})
			{
				if (next <= 500000 && next >= 0)
				{
					if (vis[sec % 2][next])continue; //짝수 , 홀수회차에 방문한 적있으면 pass 
					vis[sec & 2][next] = 1;
					q.push(next);
					if (vis[sec % 2][sis]) //짝수,홀수 회차에 동생이 해당지점을 방문할 수 있다면
					{
						cout << sec; //그것이 최소거리 (최단거리)
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
	return 0;
}
