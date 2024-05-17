// 5-17 1회차 다시풀기 30분컷 성공
#include <bits/stdc++.h>
using namespace std;

int n;
int mx = INT_MIN;//최대값 저장, 최초값은 최솟값
string str;// 최초 수식 저장 문자열
vector<int> val;//피연산자 저장 배열
vector<char> op; //연산자 저장 배열

int operate(int a, int b, char o)//연산하는 함수
{
	if (o == '+')return a + b;
	else if (o == '-') return a - b;
	else return a * b;
}
void combi(int now, int total)//완전탐색 - 조합찾기 - 괄호를 추가하거나 안하거나
{
	if (now == val.size()-1)
	{
		mx = max(mx, total);//최대값 찾기
		return;
	}

	combi(now + 1, operate(total, val[now + 1], op[now]));//추가 안한 경로
	if (now + 2 < val.size())//추가한 경로 
	{
		int temp = operate(val[now + 1], val[now + 2], op[now + 1]);
		combi(now + 2, operate(total, temp, op[now]));
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	cin >> str;
	for (auto s : str)
	{
		if (s >= '0' && s <= '9')
			val.push_back(s - '0');
		else
			op.push_back(s);
	}
	combi(0, val[0]);
	cout << mx;
	return 0;
}
