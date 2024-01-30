#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    vector<int> temp;
    int i = 0;
    for(auto a : num_list)
    {
        temp.push_back(a);
        i++;
        if(i >= n) {
            i = 0;
            answer.push_back(temp);
            temp.clear();
        }
    }
    return answer;
}