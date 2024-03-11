#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    int x = 0;
    int y = 0;
    for (string key : keyinput)
    {
        if (key == "right" && x < board[0]/2)x++;
        if (key == "left" && x > -(board[0] / 2))x--;
        if (key == "up" && y < board[1] / 2)y++;
        if (key == "down" && y > -(board[1] / 2))y--;
    }
    answer.push_back(x);
    answer.push_back(y);
    return answer;
}