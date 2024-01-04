#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	string names;
	int psum[151] = {0};
	int flag = 0;
	for (int i = 0; i < n; i++)
	{	
		cin >> names;
		psum[names[0]]++;
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		if (psum[i] >= 5)
		{
			flag = 1;
			cout << (char)i;
		}
	}
	if(flag == 0)cout<< "PREDAJA";
	return 0;
	
}