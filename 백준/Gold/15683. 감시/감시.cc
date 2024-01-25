#include <bits/stdc++.h>
using namespace std;

int n, m;
int cctv = 0;
int board[20][20];
int isChecked[20][20]; // cctv가 보고있는 방향 체크
int minc = 1000;

int wwww;

//사용중인 cctv위치 체크를 를 6로 하기 그리고 옵저브 할 때 cctv면 지나가고
// 최종 카운트할때 cctv 는 빼기
void observR(int x, int y,int r) //우측방향 진행
{
	for (int i = y; i < m; i++)
	{
		if (board[x][i] == 6)break;
		if (isChecked[x][i] == 6) continue;
		isChecked[x][i] += r; // 누적된 감시방향이 있으니 덧셈
	}
	return;
}
void observL(int x, int y, int r) //좌측
{	
	for (int i = y; i >= 0; i--)
	{
		if (board[x][i] == 6)break;
		if (isChecked[x][i] == 6) continue;
		isChecked[x][i] += r;
	}
	return;
}
void observU(int x, int y, int r) //위쪽
{
	for (int i = x; i >= 0; i--)
	{
		if (board[i][y] == 6)break;
		if (isChecked[i][y] == 6) continue;
		isChecked[i][y] += r;
	}
	return;
}
void observD(int x, int y, int r) //아래쪽
{
	for (int i = x; i < n; i++)
	{
		if (board[i][y] == 6)break;
		if (isChecked[i][y] == 6) continue;
		isChecked[i][y] += r;
	}
	return;
}
//-1 은 cctv 로 보는영역 -2 는 현재 사용중인 cctv , 0 은 사각지대 
void func(int k)
{
	if (k == cctv)
	{
		
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (isChecked[i][j] == 0) //사각지대 카운팅
				{
					cnt++;
				}
				//cout << isChecked[i][j] << "   ";
			}
			//cout << "\n";
		}
		minc = min(minc, cnt);
		//cin >> wwww;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] > 0 && board[i][j] < 6 && isChecked[i][j] != 6 ) //cctv 사용중이 아닐 경우
			{
				
				isChecked[i][j] = 6; //해당 카메라 사용중 표시
				if (board[i][j] == 1)
				{
					observR(i, j, -1);
					func(k+1);
					observR(i, j, 1); //원상복귀

					observL(i, j, -1);
					func(k + 1);
					observL (i, j, 1);

					observU(i, j, -1);
					func(k + 1);
					observU(i, j, 1);

					observD(i, j, -1);
					func(k + 1);
					observD(i, j, 1);
				}
				else if (board[i][j] == 2)
				{
					observR(i, j, -1);
					observL(i, j, -1);
					func(k + 1);
					observR(i, j, 1);
					observL(i, j, 1);

					observU(i, j, -1);
					observD(i, j, -1);
					func(k + 1);
					observU(i, j, 1);
					observD(i, j, 1);
				}
				else if (board[i][j] == 3)
				{
					observU(i, j, -1);
					observR(i, j, -1);
					func(k + 1);
					observU(i, j, 1);
					observR(i, j, 1);

					observL(i, j, -1);
					observU(i, j, -1);
					func(k + 1);
					observL(i, j, 1);
					observU(i, j, 1);

					observL(i, j, -1);
					observD(i, j, -1);
					func(k + 1);
					observL(i, j, 1);
					observD(i, j, 1);

					observD(i, j, -1);
					observR(i, j, -1);
					func(k + 1);
					observD(i, j, 1);
					observR(i, j, 1);
				}
				else if (board[i][j] == 4)
				{
					observL(i, j, -1);
					observU(i, j, -1);
					observR(i, j, -1);
					func(k + 1);
					observL(i, j, 1);
					observU(i, j, 1);
					observR(i, j, 1);
					
					observD(i, j, -1);
					observL(i, j, -1);
					observU(i, j, -1);
					func(k + 1);
					observD(i, j, 1);
					observL(i, j, 1);
					observU(i, j, 1);

					observR(i, j, -1);
					observD(i, j, -1);
					observL(i, j, -1);
					func(k + 1);
					observR(i, j, 1);
					observD(i, j, 1);
					observL(i, j, 1);

					observU(i, j, -1);
					observR(i, j, -1);
					observD(i, j, -1);
					func(k + 1);
					observU(i, j, 1);
					observR(i, j, 1);
					observD(i, j, 1);
				}
				else if (board[i][j] == 5)
				{
					observL(i, j, -1);
					observU(i, j, -1);
					observR(i, j, -1);
					observD(i, j, -1);
					func(k + 1);
					observL(i, j,1);
					observU(i, j,1);
					observR(i, j,1);
					observD(i, j,1);
					
				}
				isChecked[i][j] = 0; //다시 사용중 아니게
				return;
				
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n>>m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			isChecked[i][j] = 0;
			if (board[i][j] > 0 && board[i][j] < 6) cctv++;//cctv 개수 파악
	
			if (board[i][j] == 6)isChecked[i][j] = -1; //벽은 사각지대개수에서 빼기위해
		}
	}
	func(0);
	cout << minc;
	
}

