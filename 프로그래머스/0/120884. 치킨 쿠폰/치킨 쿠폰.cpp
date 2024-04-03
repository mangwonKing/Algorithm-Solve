#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int before = chicken;
    for(int i = 1 ; i <= chicken; i++)
    {
        if(i % 10 == 0)chicken++;
    }
    chicken -= before;
    return chicken;
}