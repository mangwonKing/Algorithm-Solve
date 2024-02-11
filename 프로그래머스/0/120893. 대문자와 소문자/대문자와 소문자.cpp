#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(auto a : my_string)
    {
        char w;
        if ( a >= 'a' && a <= 'z')
        {
            w = a - 'a';
            w += 'A';
            answer.push_back(w);
        }
        else 
        {
            w = a - 'A';
            w += 'a';
            answer.push_back(w);
        }
    }
    return answer;
}