#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    while(my_str.length() >=n)
    {
        answer.push_back(my_str.substr(0,n));
        my_str.erase(0,n);
    }
    if(!my_str.empty())
        answer.push_back(my_str);
    return answer;
}