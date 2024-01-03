#include "iostream"



using namespace std;

int main() {
	int n;
	int arr[1001];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int el;
		cin >> el;
		arr[i] = el;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			int temp;
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i]<<"\n";
	}
}