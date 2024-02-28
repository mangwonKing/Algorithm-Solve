#include <bits/stdc++.h>
using namespace std;


int n;
vector<string> nums;
bool cmp(string a, string b)
{
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string st;
		string temp;
		cin >> st;
		for (char ch : st)
		{
			if (ch >= '0' && ch <= '9')
			{
				temp.push_back(ch);
				if (temp.size() > 1 && temp[0] == '0')temp.erase(temp.begin());
			}
			else if (!temp.empty())
			{
				nums.push_back(temp);
				temp.clear();
			}
		}
		if (!temp.empty()) nums.push_back(temp);
	}
	sort(nums.begin(), nums.end(),cmp);
	for (auto a : nums)
	{
		cout << a << "\n";
	}
	return 0;
}