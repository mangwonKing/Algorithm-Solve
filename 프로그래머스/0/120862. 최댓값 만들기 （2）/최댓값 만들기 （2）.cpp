#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers) {
    int mx = INT_MIN;
    for(int i =0 ; i < numbers.size(); i++)
    {
            for(int j =0 ; j < numbers.size();j++)
            {
                if(i == j)continue;
                mx = max(mx , numbers[i]*numbers[j]);
            }
    }
    
    return mx;
}