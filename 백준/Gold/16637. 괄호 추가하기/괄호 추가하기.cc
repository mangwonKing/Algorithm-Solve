#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nums;
vector<char> ops;
int mx = INT_MIN;
int oper(char op, int a, int b)
{
	if (op == '+')return a + b;
	if (op == '-')return a - b;
	if (op == '*')return a * b;
	return -1;
}

void solution(int here, int pfs)
{
	if (here == nums.size() - 1)
	{
		mx = max(mx, pfs);
		return;
	}

	solution(here + 1, oper(ops[here], pfs, nums[here + 1]));
	if (here + 2 < nums.size())
	{
		int right = oper(ops[here + 1], nums[here + 1], nums[here + 2]);
		solution(here + 2, oper(ops[here], pfs, right));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			int a;
			cin >> a;
			nums.push_back(a);
		}
		else
		{
			char a;
			cin >> a;
			ops.push_back(a);
		}
	}
	solution(0, nums[0]);
	cout << mx;
	return 0;
}