#include <string>
#include <vector>

using namespace std;
double go2(int dy, int dx)
{
	if (dx == 0) return dy;
	return (double)dy / dx;
}

double go(vector<int> v1, vector<int>v2)
{
	int dy = (v2[1] - v1[1]);
	int dx = (v2[0] - v1[0]);
	return go2(dy, dx);
}


int solution(vector<vector<int>> dots) {
	int answer = 0;
	if (go(dots[0], dots[1]) == go(dots[2], dots[3]))answer = 1;
	else if (go(dots[0], dots[2]) == go(dots[1], dots[3])) answer = 1;
	else if (go(dots[0], dots[3]) == go(dots[2], dots[1])) answer = 1;
	return answer;
}