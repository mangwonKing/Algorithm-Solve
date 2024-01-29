#include <string>
#include <vector>
#include <map>


using namespace std;

string solution(string rsp) {
	map<char, char> psr = {
		{'2','0'} , {'0', '5'}, { '5', '2'}
	};
	string answer = "";
	for (auto a : rsp)
	{
		answer.push_back(psr[a]);
	}
	return answer;
}