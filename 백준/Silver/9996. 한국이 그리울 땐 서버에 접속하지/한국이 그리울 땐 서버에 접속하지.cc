#include <bits/stdc++.h>
using namespace std;


int n, flag;
string code;
string pre; //앞 부분
string suf; //뒷 부분
string file;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	cin >> n;
	cin >> code;
	pre = code.substr(0, code.find('*'));
	suf = code.substr(code.find('*') + 1);
	for (int i = 0; i < n; i++)
	{
		flag = true;
		cin >> file;
		if (pre.length() + suf.length() > file.length())
		{
			cout << "NE\n";
			continue;
		}
		for (int j = 0; j < pre.length(); j++)
		{
			if (file[j] != pre[j])
			{
				flag = false;
				break;
			}
		}
		for (int j = 0; j < suf.length(); j++)
		{
			if (file[file.length() - suf.length() + j] != suf[j])
			{
				flag = false;
				break;
			}
		}
		
		if (flag) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}