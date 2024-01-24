#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    for(vector<int>::iterator it = num_list.end()-1 ; it != num_list.begin()-1; it--)
    {
       answer.push_back(*it);
    }
    return answer;
}