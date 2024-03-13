#include <bits/stdc++.h>
using namespace std;


vector<string> split(string a)
{
	vector<string> s;
	while (a.find('+') != string::npos)
	{
		string temp = a.substr(0, a.find('+')-1);
		a.erase(0, a.find('+') + 2);
		s.push_back(temp);
	}
	s.push_back(a);
	return s;
}

string solution(string polynomial) {

	vector<string> str = split(polynomial);
	string left ;
	int let = 0;
	string right;
	string answer = "";
	for (string s : str)
	{
		if (s.find('x') != string::npos)
		{
			s.erase(s.find('x'),s.length());
			if (s.length() == 0) let++;
			else if (left.empty())left += s;
			else
			{
				left = to_string(stoi(left) + stoi(s));
			}
		}
		else
		{
			if (right.empty())right += s;
			else
			{
				right = to_string(stoi(right) + stoi(s));
			}
		}
	}
	if (let > 0)
	{
		if (!left.empty())left = to_string(stoi(left) + let);
		else
			left += to_string(let);
	}
		

	if (!left.empty() && !right.empty())
	{
		if (left == "1")answer = "x + " + right;
		else answer = left + "x + " + right;

	}
	else if (!left.empty())
		if (left == "1")answer = "x";
		else answer = left + 'x';
	else
		answer = right;
	

	return answer;
}