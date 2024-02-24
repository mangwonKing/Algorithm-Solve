#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
	vector<string> num;
	vector<char> op;
	int answer = 0;
	int i = 1;
	while (my_string.find('+') != string::npos || my_string.find('-') != string::npos)
	{
		if (my_string.find('+') < my_string.find('-')) op.push_back('+');
		else op.push_back('-');
		num.push_back(my_string.substr(0, my_string.find(op[op.size() - 1]) - 1));
		my_string = my_string.substr(my_string.find(op[op.size() - 1] )+ 2,my_string.length());
	}
	num.push_back(my_string);
	answer += stoi(num[0]);
	for (char o : op)
	{
		if (o == '+')answer += stoi(num[i]);
		else answer -= stoi(num[i]);
		i++;
	}
	
	return answer;
}