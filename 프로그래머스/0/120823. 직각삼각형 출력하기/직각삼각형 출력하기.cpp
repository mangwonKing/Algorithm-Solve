#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    string star = "*";
    for (int i = 0; i < n; i++)
    {
      cout << star << '\n';
      star += "*";
    }
    return 0;
}