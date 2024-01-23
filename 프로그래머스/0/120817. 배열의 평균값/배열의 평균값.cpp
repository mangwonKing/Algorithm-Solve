#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    int total = 0;
    for(auto a : numbers)
    {
        total += a;
    }
    return (double)total / numbers.size();
}