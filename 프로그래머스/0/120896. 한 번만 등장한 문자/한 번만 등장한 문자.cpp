#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> mp;
    for (auto a : s)
    {
        if (mp[a] == 0) mp[a] = 1;
        else
        {
            mp[a]++;
        }
    }
    for (auto a : mp)
    {
        if (a.second == 1)
        {
            answer.push_back(a.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}