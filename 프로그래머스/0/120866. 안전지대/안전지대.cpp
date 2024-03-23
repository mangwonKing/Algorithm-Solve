#include <string>
#include <vector>

using namespace std;

int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int vis[102][102];
int solution(vector<vector<int>> board) {
	int answer = 0;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == 1 && vis[i][j] != 2)
			{
				vis[i][j] = 1;
				for (int k = 0; k < 8; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size())continue;
					if (board[ny][nx] == 1)continue;
					board[ny][nx] = 1;
					vis[ny][nx] = 2;
				}
			}
			
		}
	}
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)
		{
			if (board[i][j] == 0)answer++;
		}
	}
	return answer;
}