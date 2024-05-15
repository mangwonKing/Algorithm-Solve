//5/15 다시풀기 성공
#include <bits/stdc++.h>
using namespace std;

int city[52][52];
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<pair<int, int>> chlist;
int n, m;
int mn = 987654321;

int dist(pair<int, int> a, pair<int, int>b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
void choice(int now)
{
    if (chlist.size() == m)
    {
        int total = 0;
        for (auto h : home)
        {
            int m = 987654321;
            for (auto ch : chlist)
            {
                int temp = dist(ch, h);
                if (m > temp) m = temp;
            }
            total += m;
        }
        if (mn > total) mn = total;
        return;
    }

    for (int i = now; i < chicken.size(); i++)
    {
        chlist.push_back({ chicken[i].first ,chicken[i].second });
        choice(i + 1);
        chlist.pop_back();
        choice(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //getline(cin, str); 공백 포함 입력받기
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 1)home.push_back({ i,j });
            else if (city[i][j] == 2) chicken.push_back({ i,j });
        }
    }
    choice(0);
    cout << mn;
    return 0;
}
