#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    int cnt = money / 5500;
    answer.push_back(cnt);
    answer.push_back(money - (cnt * 5500));
    
    return answer;
}