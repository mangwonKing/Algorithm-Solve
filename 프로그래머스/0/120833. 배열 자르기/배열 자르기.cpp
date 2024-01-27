#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    vector<int> answer;
    for(auto it = numbers.begin() + num1; it != numbers.begin()+num2+1; ++it)
    {
        answer.push_back(*it);
    }
    return answer;
}