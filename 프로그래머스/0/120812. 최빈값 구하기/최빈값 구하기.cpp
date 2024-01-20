#include <bits/stdc++.h>

using namespace std;

int cnt[1001];
int solution(vector<int> array) {
    for(auto a : array)
    {
        cnt[a]++;
    }
    int max = -1;
    int maxi = -1;
    int flag = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(cnt[i] > max)
        {
            maxi = i;
            max = cnt[i];
            flag = 0;
        }
        else if (cnt[i] == max)
        {
            flag = 1;
        }
    }
    if(flag)return -1;
    else return maxi;
}