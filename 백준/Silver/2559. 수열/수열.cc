#include <bits/stdc++.h>
using namespace std;

int main() {
	//getline(cin, str);
	int n, k;
	int max;
	vector<int> psum;
	cin >> n >> k;
	//누적합 구하기
	psum.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		psum.push_back(psum[i - 1] + tmp);
	}
	//누적합 중 부분합 추출해서 최댓값 구하기 
	max = psum[k];
	for (int i = k; i <= n; i++)
	{	
		int sum = psum[i] - psum[i - k];
		if (max < sum) {
			max = sum;
		}
	}
	cout << max;
	
	return 0;
	
}