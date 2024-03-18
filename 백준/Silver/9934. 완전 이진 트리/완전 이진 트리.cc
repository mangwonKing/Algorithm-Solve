#include <bits/stdc++.h>
using namespace std;

int nums[2050];
int tree[2050];
int k;

int cnt = 0;
void inOrder(int now)
{
	if (tree[now*2] == 0) //tree의 마지막 이라면
	{
		tree[now] = nums[++cnt];
		return;
	}
	inOrder(now * 2);
	tree[now] = nums[++cnt];
	inOrder(now * 2 + 1);

}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> k;
	for (int i = 1; i < pow(2, k); i++)
	{
		cin >> nums[i];
		tree[i] = 1;
	}
	inOrder(1);
	for (int i = 1; i <= k; i++)
	{
		for (int j = pow(2,i-1); j < pow(2, i); j++)
		{
			cout << tree[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}