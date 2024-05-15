#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //getline(cin, str); 공백 포함 입력받기
    string str;
    string code;
    getline(cin, str);

    for (auto s : str)
    {
        if (s >= 'a' && s <= 'z')
        {
            if (s + 13 > 'z')code.push_back(s + 13 - 'z' + 'a'-1);
            else code.push_back(s + 13);
        }
        else if (s >= 'A' && s <= 'Z')
        {
            if (s + 13 > 'Z')code.push_back(s + 13 - 'Z' + 'A'-1);
            else code.push_back(s + 13);
        }
        else
        {
            code.push_back(s);
        }
    }
    cout << code;
    return 0;
}
