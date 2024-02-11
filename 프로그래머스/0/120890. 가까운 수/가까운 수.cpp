#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    int min = 100;
    for(auto a : array)
    {
        if(abs(a-n) < min)
        {
            answer = a;
            min = abs(a - n);
        }
        if(abs(a-n) == min)
        {
            if(answer > a ) answer = a;
        }
    }
    return answer;
}