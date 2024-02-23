#include <bits/stdc++.h>
using namespace std;


vector<int> adj[10002];
int vis[10002]; // 정점별 방문 처리
int hk[10002];
int n, m;
int mx = -1;
int dfs(int here)
{
	vis[here] = 1;
	int ret = 1;
	for (int there : adj[here])
	{
		if (vis[there] == 1) continue;
		ret += dfs(there);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m;
	// 1. 인접 리스트로 그래프 구현
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		adj[b].push_back(a);
	}
	//2. 정점별 dfs
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		int cnt = 0;
		hk[i] = dfs(i);
		mx = max(hk[i], mx);
	}
	for (int i = 1; i <= n; i++)if (mx == hk[i]) cout << i << " ";
		
	return 0;
}