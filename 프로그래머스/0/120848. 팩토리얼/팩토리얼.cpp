#include <string>
#include <vector>

using namespace std;

int fact(int n)
{
	if (n == 1) return 1;

	return n * fact(n - 1);
}

int solution(int n) {
	int answer = 0;
	for (int i = 1; i <= 10; i++)
	{
		if (fact(i) > n) break;
		answer = i;
	}
	return answer;
}