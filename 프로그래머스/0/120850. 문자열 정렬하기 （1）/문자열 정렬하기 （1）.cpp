#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    for (auto a : my_string)
    {
        if (a >= '0' && a <= '9')
            answer.push_back(a - '0');
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}