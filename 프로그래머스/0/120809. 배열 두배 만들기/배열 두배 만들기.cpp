#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    
    vector<int> answer;
    for(auto a : numbers)
    {
        answer.push_back(a * 2);
    }
    
    return answer;
}