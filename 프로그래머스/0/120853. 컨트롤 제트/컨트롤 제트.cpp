#include <string>
#include <vector>

using namespace std;

vector<string> split(string dest, char deli)
{
	vector<string> temp;
	int pos = 0;
	while (dest.find(deli) != string::npos)
	{	
		temp.push_back(dest.substr(0, dest.find(deli)));
		pos = dest.find(deli);
		dest.erase(dest.begin(), dest.begin() + pos+1);
	}
	temp.push_back(dest);
	return temp;
}

int solution(string s) {
	int answer = 0;
	vector<string> num = split(s, ' ');
	int prev = 0;
	for (auto a : num)
	{
		if (a != "Z")
		{
			answer += stoi(a);
			prev = stoi(a);
		}
		else
		{
			answer -= prev;
		}
	}
	return answer;
}