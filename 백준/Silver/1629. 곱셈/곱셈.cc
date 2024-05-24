//5/24 다시풀기 성공 , 외우지말고 생각해서 풀기
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c;

ll go(ll now)//(a * a) % c  = ((a%c)*(a%c))%c 임을 이용
{
	if (now == 1)
		return a % c;
	if (now % 2 == 0)return go(now / 2) * go(now / 2) % c; // 짝수승
	else return go(now-1) * go(1) % c; //홀수승은 짝수로 만들어주기
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기 
	cin >> a >> b >> c;

	cout << go(b);
	return 0;
}
