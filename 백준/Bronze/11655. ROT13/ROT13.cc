#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 65 && str[i] < 97) {
			if (str[i] + 13 > 'Z') str[i] = str[i] + 13 - 'Z' + 'A' - 1;
			else str[i] += 13;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			if (str[i] + 13 > 'z') str[i] = str[i] + 13 - 'z' + 'a' - 1;
			else str[i] += 13;
		}
	}
	cout << str;
	return 0;
	
}