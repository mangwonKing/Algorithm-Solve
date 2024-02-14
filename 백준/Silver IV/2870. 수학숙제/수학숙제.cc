#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<string> homework;
vector<string> answer;
int n;

bool cmp(const string a, const string b)
{
	if (a.size() == b.size())
	{
		return a < b;
	}
	return a.size() < b.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	while (n > 0)
	{
		n--;
		string line;
		string temp;
		cin >> temp;
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] >= '0' && temp[i] <= '9')
			{
				line.push_back(temp[i]);
			}
			else
			{
				if (line.size() != 0)
				{
					homework.push_back(line);
					line.clear();
				}
			}
			if (i == temp.size() - 1 && line.size() != 0)
			{
				homework.push_back(line);
			}
		}
	}
	//size 가 0 인데 0이 주어지면 무시
	for (auto a : homework)
	{
		
		string temp;
		for (int i = 0; i < a.size(); i++)
		{
			if (temp.size() == 1 && temp[0] == '0')
			{
				temp.pop_back();
			}
			temp.push_back(a[i]);
		}
		if (temp[0] == '0' && temp.size() > 1)temp.erase(temp.begin());
		answer.push_back(temp);
	}
	sort(answer.begin(), answer.end(), cmp);
	for (auto a : answer)
	{
		cout << a << "\n";
	}
	return 0;
}