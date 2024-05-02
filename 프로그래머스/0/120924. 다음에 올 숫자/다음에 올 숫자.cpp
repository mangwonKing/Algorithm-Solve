#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int n = common.size() - 1;
    int dif = common[n] - common[n - 1];
    if (dif == common[n - 1] - common[n - 2])return common[n] + dif;
    else return common[n] * (common[n] / common[n - 1]);
}