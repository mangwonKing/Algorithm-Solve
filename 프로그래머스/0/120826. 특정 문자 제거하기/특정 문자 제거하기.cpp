#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for (auto a : my_string)
    {
        if (a == letter[0]) continue;
        answer.push_back(a);
    }
    return answer;
}