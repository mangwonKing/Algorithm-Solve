#include <bits/stdc++.h>
using namespace std;
int solution(int num, int k) {
	string a = to_string(num);
	if (a.find('0' + k) != string::npos) return a.find('0' + k) + 1;
	return a.find('0'+k);
}