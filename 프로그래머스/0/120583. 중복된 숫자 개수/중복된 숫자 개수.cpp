#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    for(auto a : array)
        if(a == n)answer++;
    return answer;
}