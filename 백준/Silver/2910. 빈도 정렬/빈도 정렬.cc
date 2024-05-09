// 5/9 1회차 다시풀기 성공
#include <bits/stdc++.h>
using namespace std;

int n, c;
map<int, int> code;
map<int, int> pass;
vector<pair<int, int>> code2;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return pass[a.first] < pass[b.first];
    }
    return a.second > b.second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //getline(cin, str); 공백 포함 입력받기
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        code[a]++;
        if (pass[a] == 0) 
        {
            if (i == 0)pass[a] = 1;
            else pass[a] = i+1; 
        }
    }
    for (auto a : code)
    {
        code2.push_back({ a.first,a.second });
    }
    sort(code2.begin(), code2.end(), cmp);
    for (auto a : code2)
    {
        for (int i = 0; i < a.second; i++)
        {
            cout << a.first << " ";
        }
    }
    return 0;
}
