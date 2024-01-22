#include <bits/stdc++.h>
using namespace std;


int solution(int n) 
{
    int size = 7;
    int div;
    div = n / size;
    if(n % size != 0 )div++;

    return div;
}