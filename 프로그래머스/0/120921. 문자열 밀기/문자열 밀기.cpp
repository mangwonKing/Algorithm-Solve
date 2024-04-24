#include <string>
#include <vector>

using namespace std;

string moveR(string str)
{
    string res = str;
    for (int i = 0; i < str.size(); i++)
    {
        if (i == 0)
        {
            res[i] = str[str.size() - 1];
        }
        else
        {
            res[i] = str[i-1];
        }
    }
    return res;
}
int solution(string A, string B) {
    if (A == B) return 0;
    int answer = 0;
    while (1)
    {
        A = moveR(A);
        answer++;
        if (A == B) return answer;
        if (answer > A.size())return -1;
    }
}