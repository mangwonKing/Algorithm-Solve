#include <bits/stdc++.h>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


int pan[102][102];
int visited[102][102];
int edge[102][102];
int area;
int n, m;
int cnt = 0;

bool melted = true;
void dfs(int y , int x)
{
	visited[y][x] = 1;
	area++;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
		if (visited[ny][nx] == 1 || pan[ny][nx] == 0)continue;
		
		dfs(ny, nx);
	}
}

bool inCheese;
vector<pair<int, int>> notAir;
void airDfs(int y, int x)
{
	visited[y][x] = 1;
	if (inCheese) notAir.push_back({ y, x }); // 치즈 속 이라고 가정하고 좌표 넣어두기
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
		{
			if (inCheese) inCheese = false; //영역 밖까지 되어있으니 치즈 속이 아님
			notAir.clear(); //담아둔 좌표 날리기
			continue;
		}
		if (visited[ny][nx] == 1 || pan[ny][nx]== 1)continue;
		

		airDfs(ny, nx);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> pan[i][j];
			if (melted == true &&pan[i][j] == 1 )
			{
				melted = false;
			}
		}
	}
	while (!melted) // 치즈 녹이기 시작
	{
		// 치즈 영역 구하기
		area = 0; // area 초기화
		memset(visited, 0, sizeof(visited)); // visited 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (pan[i][j] == 1 && visited[i][j] == 0)
					dfs(i, j);
			}
		}
		//cout << area;
		// 
		// 공기영역 연관컴포넌트 찾고 치즈속 특수 처리
		memset(visited, 0, sizeof(visited));// visited 초기화
		notAir.clear(); // 새로운 영역이니 초기화하고 진행
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (pan[i][j] == 0 && visited[i][j] == 0)
				{
					inCheese = true;
					airDfs(i, j);
					if (inCheese)
					{
						for (auto a : notAir)
						{
							pan[a.first][a.second] = 3; //3 은 치즈속 공간 의미
						}
					}
				}
				
			}
		}

		//cout << "------------------------------\n";// 디버깅 라인
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << pan[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		// 치즈속이 아닌 순수 공기와 맞닿는 치즈 찾고 0으로 변경 그리고 치즈속 공간처리 원위치
		memset(edge, 0, sizeof(edge));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (pan[i][j] == 1)
				{
					for (int k = 0; k < 4; k++) // 주위에 공기와 맞닿았다면
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (pan[ny][nx] == 0 && edge[ny][nx] == 0) //그 공기가 치즈가 있던곳인지도 확인
						{
							pan[i][j] = 0;
							edge[i][j] = 1;
							break;
						}
					}
				}
			}
		}
		if (inCheese) //치즈속 공간이 존재했다면 
		{
			for (auto a : notAir)
			{
				pan[a.first][a.second] = 0; //다시 0으로 돌려주기
			}
		}

		//cout << "------------------------------\n"; // 디버깅 라인
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cout << pan[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		// 횟수 ++
		cnt++;
		// pan 검사 (모두 0이 되었는지) 맞으면 break
		melted = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (pan[i][j] == 1)
				{
					melted = false;
					break;
				}
			}
		}
		//cout << cnt<<" 회 ------------------------------\n";// 디버깅 라인
	}
	cout << cnt << "\n" << area;

	return 0;
}