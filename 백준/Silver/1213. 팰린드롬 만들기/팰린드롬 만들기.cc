#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	string name;
	string pel;
	int word[100] = { 0 };
	int size;
	int flag = 0;
	cin >> name;
	size = name.size();
	pel = name;

	for (int i = 0; i < name.size(); i++)
	{
		word[name[i]]++;
		//cout << name[i] <<" : "<<word[name[i]] << "\n";
	}
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (word[i] % 2 != 0) //홀수개수 발견
		{
			flag++;
			if (size % 2 != 0 && flag >= 2) { // 전체길이 홀수 , 홀수인단어 2개이상
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			if (size % 2 == 0 && flag > 0) { // 전체길이 짝수 , 홀수인단어 존재
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}
	int j = 0;
	for (int i = 'A'; i <= 'Z'; i++)
	{
		if (word[i] > 1) {
			while (word[i] > 1) {
				pel[j++] = i;
				pel[size - j] = i;
				word[i] -= 2;
			}
			if (word[i] == 1) {
				pel[size / 2] = i;
				word[i]--;
			}
		}
		else if (word[i] == 1) {
			pel[size / 2] = i;
		}
	}
	cout << pel;
	return 0;
	
}