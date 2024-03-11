#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> dots) {
	int answer = 0;
	set<int> x;
	set<int> y;
	for (auto dot : dots)
	{
		x.insert(dot[0]);
		y.insert(dot[1]);
	}
	vector<int> nx(x.begin(),x.end());
	vector<int> ny(y.begin(),y.end());
	answer = (abs(nx[0] - nx[1]) * abs(ny[0] - ny[1]));
	return answer;
}