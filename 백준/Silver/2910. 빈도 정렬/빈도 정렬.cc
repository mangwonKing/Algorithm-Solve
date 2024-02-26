#include <bits/stdc++.h>
using namespace std;

using ll = long long;
map<ll,ll> mp;
map<ll, ll> mp2;
vector <pair<ll, ll>> v;
int n, c;

bool cmp(pair<ll, ll> a, pair<ll, ll>b)
{
	if (a.second == b.second)
		return mp2[a.first] < mp2[b.first];
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		mp[a]++;
		if (mp2[a] == 0)
			mp2[a] = i+1;
	}
	for (auto a : mp)
	{
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto a : v)
	{
		for (int i = 0; i < a.second; i++)
		{
			cout << a.first << " ";
		}
		
	}
	return 0;
}