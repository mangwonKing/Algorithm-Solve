#include <string>
#include <vector>

using namespace std;
int arr[201];
int solution(vector<vector<int>> lines) {
	int answer = 0;
	for (auto line: lines)
	{
		for (int i = line[0]; i < line[1]; i++)
		{
			int idx = i;
			if (idx < 0) idx += 200;
			arr[idx]++;
		}
	}
	for (int i = 0; i <= 200; i++)
		if (arr[i]>1)answer++;
	return answer;
}