// 5-13 다시풀이 20분컷 
// 아쉬운점 : total 을 구할 필요 없었음 그냥 area의 size 가 총 영역의 개수임

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int total = 0;
int paper[102][102];
int vis[102][102];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<int> area;

int dfs(int a,int b)
{
    vis[a][b] = 1;
    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = a + dy[i];
        int nx = b + dx[i];
        if (ny >= n || ny < 0 || nx >= m || nx < 0)continue;
        if (vis[ny][nx] != 0 || paper[ny][nx] == 1) continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //getline(cin, str); 공백 포함 입력받기
    cin >> n >> m >> k; 
    for (int i = 0; i < k; i++)
    { // x , y
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = y1; j < y2; j++)
        {
            for (int k = x1; k < x2; k++)
            {
                paper[j][k] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (paper[i][j] == 0 && vis[i][j] == 0)
            {
                total++;
                area.push_back(dfs(i,j));
            }
        }
    }
    sort(area.begin(), area.end());
    cout << total<<"\n";
    for (auto a : area)
        cout << a << " ";
    return 0;
}
