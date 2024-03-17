#include <bits/stdc++.h>
using namespace std;


int n;
string mx = "0";
string mn = "9999999999";

char op[12];
string str;
vector<int>nums;

bool sign(int idx, int r)
{
	if (op[idx] == '>') return nums[idx] > r;
	else return nums[idx] < r;
}

void tostring()
{
	str.clear();
	for (int a : nums)
	{
		str.push_back(a + '0');
	}
	return;
}
void go(int size)
{
	if (size == n)
	{
		tostring();
		mx = max(mx, str);
		mn = min(mn, str);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (find(nums.begin(),nums.end(),i)!= nums.end())continue;
		if (sign(size , i))
		{
			nums.push_back(i);
			go(size + 1);
			nums.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> op[i];

	
	for (int i = 0; i <= 9; i++)
	{
		nums.push_back(i);
		go(0);
		nums.pop_back();
	}
	cout << mx << "\n" << mn;
	return 0;
}