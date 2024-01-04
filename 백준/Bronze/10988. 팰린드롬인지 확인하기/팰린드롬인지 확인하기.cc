#include <bits/stdc++.h>
using namespace std;

int main() {
	string word;
	cin >> word;
	int n = word.size();
	
	for (int i = 0; i < n / 2; i++)
	{
		if (word[i] != word[n - i - 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
	
}