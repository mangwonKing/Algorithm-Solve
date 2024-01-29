#include <string>
#include <vector>

using namespace std;

int cnt = 0;
vector<int> a;

void comp(int ix, int n, int m, int size)
{
	if (size == m)
	{
		cnt++;
		return;
	}

	for (int i = ix; i < n; i++)
	{
		a.push_back(i);
		comp(i+1, n, m,a.size());
		a.pop_back();
	}
	return;
}
int solution(int balls, int share) {

	comp(0, balls, share, 0);
	return cnt;
}