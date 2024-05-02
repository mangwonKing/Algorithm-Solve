#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int n = total / num;
    if (total % num == 0)
    {
        answer.push_back(n);
        int i = 1;
        while (answer.size() < num)
        {
            answer.push_back(n+i);
            answer.push_back(n-i);
            i++;
        }
    }
    else
    {
        answer.push_back(n);
        answer.push_back(n+1);
        int i = 1;
        while (answer.size() < num)
        {
            answer.push_back(n - i);
            answer.push_back((n+1) + i);
            i++;
        }
        
    }
    sort(answer.begin(), answer.end());
    return answer;
}