// 5/8 다시 푼것
#include <bits/stdc++.h>
using namespace std;

int city[52][52];
int minc = INT_MAX;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> Select;

int n, m;

int calDist(pair<int, int> a, pair <int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void go(int now)
{
    if (Select.size() == m)
    {
        int total = 0;
        for (auto h : home)
        {
            int tmp = 987654321;
            for (auto s : Select)
            {
                int dist = calDist(h, s);
                if (tmp > dist)tmp = dist; //각 집별로 최소인 치킨거리 더해주기
            }
            total += tmp;
        }
        if (minc > total) minc = total;
        return;
    }

    for (int i = now; i < chicken.size(); i++)
    {
        Select.push_back(chicken[i]);
        go(i + 1);
        Select.pop_back();
        go(i + 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //getline(cin, str); 공백 포함 입력받기
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 1)home.push_back({ i,j });
            else if (city[i][j] == 2)chicken.push_back({ i,j });
        }
    }
    go(0);
    cout << minc;
    return 0;
}
