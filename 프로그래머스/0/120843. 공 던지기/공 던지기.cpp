#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {

	int answer = 0;
	int idx = 0;
	while (k > 1)
	{
		if (idx + 2 >= numbers.size())
		{
			idx = (idx + 2) - (numbers.size()); // 4  6
		}
		else
		{
			idx += 2;
		}
		k--;
	}
	return numbers[idx];

}