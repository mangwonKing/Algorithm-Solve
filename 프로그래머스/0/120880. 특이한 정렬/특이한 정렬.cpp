#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
	vector<int> answer;
	int size = numlist.size();
	while(numlist.size())
	{
		int mn = 999999;
		int temp = 0;
		for (int j = 0; j < numlist.size(); j++)
		{
			if (abs(numlist[j] - n) < mn)
			{
				mn = abs(numlist[j] - n);
				temp = j;
			}
			else if(abs(numlist[j] - n) == mn)
			{
				if (numlist[temp] < numlist[j])temp =j;
			}
		}
		answer.push_back(numlist[temp]);
		numlist.erase(numlist.begin() + temp);
	}
	return answer;
}