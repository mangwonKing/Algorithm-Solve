#include <bits/stdc++.h>
using namespace std;

int n;
int mp, mf, ms, mv;

int mn = INT_MAX;

int foods[17][5];
int food[5];
vector<int> selected;
vector<int> choice;

void select(int now ,int price)
{
	if (price >= mn) return;
	if (mp <= food[0] && mf <= food[1] && ms <= food[2] && mv <= food[3])
	{
		if (mn > price) {
			selected = choice;
			mn = price;
		}
		return;
	}

	for (int i = now; i < n; i++)
	{
		choice.push_back(i);
		food[0] += foods[i][0];
		food[1] += foods[i][1];
		food[2] += foods[i][2];
		food[3] += foods[i][3];
		select(i + 1, price + foods[i][4]);
		choice.pop_back();
		food[0] -= foods[i][0];
		food[1] -= foods[i][1];
		food[2] -= foods[i][2];
		food[3] -= foods[i][3];

	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		cin >> foods[i][0] >> foods[i][1] >> foods[i][2] >> foods[i][3] >> foods[i][4];
	}
	select(0,0);
	if (mn == INT_MAX) {
		cout << -1;
		return 0;
	}
	cout << mn<<"\n";
	for (int a : selected)
		cout << a+1 << " ";
}