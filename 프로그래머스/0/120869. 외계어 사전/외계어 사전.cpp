#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    for (string s : dic)
    {
        int cnt = 0;
        for (string sp : spell)
        {
            if (s.find(sp) != string::npos)
                cnt++;
        }
        if (cnt == spell.size())return 1;
    }
    return 2;
}