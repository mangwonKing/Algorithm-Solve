#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
	string answer = "";
	map<string, string> database;

	for (auto a : db)
	{
		database[a[0]] = a[1];
	}
	if (database[id_pw[0]] == "")return "fail";
	if (database[id_pw[0]] != id_pw[1]) return "wrong pw";
	return "login";
}