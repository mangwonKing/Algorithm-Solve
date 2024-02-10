#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
	
	int m = -1;
	int sum = 0;
	for (auto a : sides)
	{
		sum += a;
		if (a > m) m = a;
	}
	if (sum - m > m) return 1;
	else return 2;
}