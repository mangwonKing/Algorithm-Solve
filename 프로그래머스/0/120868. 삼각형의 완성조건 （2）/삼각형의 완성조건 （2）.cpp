#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int mx = max(sides[0],sides[1]);
    int mn = min(sides[0],sides[1]);
    for(int i = 1; i <= mx; i++)
    {
        if(mx < i + mn)answer++;
    }
    int sum = sides[0] + sides[1];
    for(int i = mx+1; i < sum; i++)
    {
        if(i < sum)answer++;
    }
    return answer;
}