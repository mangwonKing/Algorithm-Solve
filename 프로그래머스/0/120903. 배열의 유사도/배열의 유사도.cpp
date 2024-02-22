#include <string>
#include <vector>

using namespace std;
int solution(vector<string> s1, vector<string> s2) {
	int answer = 0;
	
	for (auto s : s1)
		for (auto w : s2)
			if (s == w)answer++;
	return answer;
}