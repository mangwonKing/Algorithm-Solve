#include <bits/stdc++.h>

using namespace std;

map<string, char> morse;
void morseInit()
{
	morse.insert({ ".-", 'a' });
	morse.insert({ "-...", 'b' });
	morse.insert({ "-.-.", 'c' });
	morse.insert({ "-..", 'd' });
	morse.insert({ ".", 'e' });
	morse.insert({ "..-.", 'f' });
	morse.insert({ "--.", 'g' });
	morse.insert({ "....", 'h' });
	morse.insert({ "..", 'i' });
	morse.insert({ ".---", 'j' });
	morse.insert({ "-.-", 'k' });
	morse.insert({ ".-..", 'l' });
	morse.insert({ "--", 'm' });
	morse.insert({ "-.", 'n' });
	morse.insert({ "---", 'o' });
	morse.insert({ ".--.", 'p' });
	morse.insert({ "--.-", 'q' });
	morse.insert({ ".-.", 'r' });
	morse.insert({ "...", 's' });
	morse.insert({ "-", 't' });
	morse.insert({ "..-", 'u' });
	morse.insert({ "...-", 'v' });
	morse.insert({ ".--", 'w' });
	morse.insert({ "-..-", 'x' });
	morse.insert({ "-.--", 'y' });
	morse.insert({ "--..", 'z' });
}

vector<string> split(string str, char deli)
{
	vector<string> a;
	string b;
	string::iterator it = str.begin();
	int i = 0;
	while (it != str.end())
	{
		if (*it != deli)
		{
			b.push_back((*it));
			++it;
		}
		else
		{
			++it;
			a.push_back(b);
			b.clear();
		}
	}
	a.push_back(b);
	return a;
}

string solution(string letter) {
	morseInit();
	string answer = "";
	vector<string> mstr = split(letter, ' ');
	for (auto a : mstr)
	{
		answer.push_back(morse[a]);
	}
    
    return answer;
}