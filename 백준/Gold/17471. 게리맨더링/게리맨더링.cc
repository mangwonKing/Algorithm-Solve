#include <bits/stdc++.h>
using namespace std;

vector<int> v[12];
int vis[12];
int pop[12];
int total = 0;
int n;
int mn = INT_MAX;

void dfs(int here,vector<int> s)
{
	vis[here] = 1;
	//cout <<here<<" 방문 \n";
	for (auto a : v[here])
	{
		if (vis[a])continue;
		if (find(s.begin(), s.end(), a) == s.end()) continue;
		dfs(a, s);
	}
}

bool check(vector<int> s)
{
	
	// 벡터 0번째 인덱스부터 해서 dfs 돌아서
	// 모든곳에 방문했으면(즉 모든 원소가 벡터에 들어가있으면)
	// 클리어 아닐까?

	memset(vis, 0, sizeof(vis));
	//cout << "----------------\n";
	dfs(s[0],s);
	//cout << "--------------\n";
	for (int i = 0; i < s.size(); i++)
	{
		if (vis[s[i]] == 0)return false;
	}
	/*cout << " 가능합니다 이 조합 ->";
	for (auto q : s)
		cout << q << " ,";
	cout << "\n";*/
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pop[i];
		total += pop[i];
	}

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int a;
			cin >> a;
			v[i].push_back(a-1);
		}
	}
	for (int i = 0; i < (1 << n); i++)
	{
		vector<int> s;
		vector<int> s2;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) //그룹 a
			{
				s.push_back(j);
			}
			else // 그룹 b
			{
				s2.push_back(j);
			}
		}
		
		if (s.size() == n || s2.size() == n)continue;
		if (!check(s) || !check(s2))continue; // 두 그룹이 각각 연결되어 있는지
		/*cout << "통과된 조합 : ";
		for (auto q : s)
			cout << q << " ,";
		cout << "\n";*/

		int agroup = 0;
		for (int j = 0; j < s.size(); j++)
		{
			agroup += pop[s[j]];
		}
		int bgroup = total - agroup;
		//cout << " 이번 1그룹의 인구수: " << agroup << "\n";
		//cout << " 이번 2그룹의 인구수: " << bgroup << "\n";
		mn = min(mn, abs(agroup - bgroup));
	}
	if (mn == INT_MAX) mn = -1;
	cout << mn;
}