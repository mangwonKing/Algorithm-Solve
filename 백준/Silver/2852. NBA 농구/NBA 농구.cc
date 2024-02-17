#include <bits/stdc++.h>
using namespace std;

int t;
int team1 = 0;
int team2 = 0;
map<int, int> win;
int start1 = -1;
int start2 = -1;
int toTime(string str) //mm:ss -> second
{
	string min;
	string sec;
	
	min.push_back(str[0]);
	min.push_back(str[1]);
	sec.push_back(str[3]);
	sec.push_back(str[4]);

	return stoi(min)* 60 + stoi(sec);
}
string toStr(int time)
{
	string t;
	int min = time / 60;
	int sec = time % 60;

	if (min > 9)
	{
		t.push_back('0' + min / 10);
		t.push_back('0' + min % 10);
	}
	else {
		t.push_back('0');
		t.push_back('0' + min);
	}
	t.push_back(':');
	if (sec > 9)
	{
		t.push_back('0' + sec / 10);
		t.push_back('0' + sec % 10);
	}
	else {
		t.push_back('0');
		t.push_back('0' + sec);
	}
	return t;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//getline(cin, str); 공백 포함 입력받기
	
	cin >> t;
	while (t > 0)
	{
		t--;
		int goal;
		string time;
		cin >> goal >> time;
		if (goal == 1) team1++;
		else team2++;

		if (team1 == team2)
		{
			if (start1 != -1)
			{
				win[0] += toTime(time) - start1; //1 이 앞선 시간 기록
				start1 = -1;
			}
			else
			{
				win[1] += toTime(time) - start2; //2 이 앞선 시간 기록
				start2 = -1;
			}
		}
		else if (team1 > team2 && start1 == -1)
		{
			start1 = toTime(time);
		}
		else if (team1 < team2 && start2 == -1)
		{
			start2 = toTime(time);
		}
	}
	if (start1 != -1)
	{
		win[0] += toTime("48:00") - start1;
		
	}
	else if (start2 != -1)
	{
		win[1] += toTime("48:00") - start2;
	}
	cout <<toStr(win[0]) <<"\n";
	cout << toStr(win[1]) <<"\n";
	return 0;
}