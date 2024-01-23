#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int a = slice;
    while(1)
    {
        if(slice >= n) break;
        slice += a;
    }
    return slice / a;
}