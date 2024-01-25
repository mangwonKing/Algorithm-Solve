#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int n2 = 0;
    int n3 = 0;
    vector<int> answer;
    for(auto a : num_list)
    {
        (a % 2 == 0) ? n2++ : n3++;
    }
    answer.push_back(n2);
    answer.push_back(n3);
   
    return answer;
}