#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
	for (auto a : my_string)
	{
		if (a >= '0' && a <= '9')
		{
			answer += a - '0';
		}
	}
    return answer;
}