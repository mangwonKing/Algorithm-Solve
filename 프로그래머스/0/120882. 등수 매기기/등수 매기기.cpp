#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
	vector<int> answer;
	vector<double> average;
	for (auto a : score)
	{
		average.push_back((double)(a[0] + a[1]) / 2);
	}
	for (int i = 0; i < average.size(); i++)
	{
		int x = 1;
		for (int j = 0; j < average.size(); j++)
		{
			if (average[i] < average[j])x++;
		}
		answer.push_back(x);
	}
	return answer;
}