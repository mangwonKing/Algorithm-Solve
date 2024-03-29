#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> num;
vector<char> op;
int mx = INT_MIN;
int oper(int a, int b ,int idx)
{
	if (op[idx] == '+')return a + b;
	else if (op[idx] == '-')return a - b;
	else return a * b;
}

void solution(int now, int sum)
{
	if (now == num.size() - 1)
	{
		mx = max(mx, sum);
		return;
	}

	solution(now + 1, oper(sum, num[now + 1], now));
	if (now + 2 >= num.size()) return;
	int temp = oper(num[now + 1], num[now + 2], now + 1);
	solution(now + 2, oper(sum, temp, now));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		if (i % 2 == 0) {
			int a;
			cin >> a;
			num.push_back(a);
		}
		else
		{
			char c;
			cin >> c;
			op.push_back(c);
		}
	}
	solution(0, num[0]);
	cout << mx;

}