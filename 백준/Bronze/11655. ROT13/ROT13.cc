#include <bits/stdc++.h>
using namespace std;

int main() {
	string str;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			for (int j = 0; j < 13; j++)
			{
				str[i]++;
				if (str[i] > 'z')
				{
					str[i] = str[i] - 'z' + 'a' - 1;
				}
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 13;
			if (str[i] > 'Z')
			{
				str[i] -= 'Z';
				str[i] += 'A';
				str[i] -= 1;
			}
		}
	}
	cout << str;
	return 0;
	
}