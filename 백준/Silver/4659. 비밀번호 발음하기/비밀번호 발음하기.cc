#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string password;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	cin >> password;
	while (password != "end")
	{
		char temp;
		bool haveVow = false;
		bool accept = true;
		int vow = 0; //모음
		int con = 0; //자음
		for (int i = 0 ; i < password.size(); i++)
		{
			if (i != 0)
			{
				if (temp != 'e' && temp != 'o' && temp == password[i]) //연속으로 등장
				{
					accept = false;
					break;
				}
			}
			if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') //모음
			{
				haveVow = true;
				con = 0;
				vow++;
			}
			else //자음
			{
				vow = 0;
				con++;
			}
			if (vow == 3 || con == 3)
			{
				accept = false;
				break;
			}
			temp = password[i];
		}
		if (haveVow == false || accept == false)
		{
			cout << "<" << password << "> is not acceptable.\n";
		}
		else
		{
			cout << "<" << password << "> is acceptable.\n";
		}
		cin >> password;
	}
	
	return 0;
}