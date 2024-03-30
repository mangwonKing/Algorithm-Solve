#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
	int i = 2;
	while (i <= a)
	{
		if (a % i == 0 && b % i == 0)
		{
			a /= i;
			b /= i;
			i = 1;
		}
		i++;
	}
	for (int i = 2; i <= b; i++)
	{
		if (b % i == 0)
		{
			if (i % 2 != 0 && i % 5 != 0)return 2;
		}
	}
	return 1;
}