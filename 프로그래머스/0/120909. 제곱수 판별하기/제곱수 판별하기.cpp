#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    for(int i = 1 ; i <= n / 2 ; i++)
        if( n  == i * i)return 1;
    return 2;
}