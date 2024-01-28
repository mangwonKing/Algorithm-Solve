#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    int attack = 5;
    while(hp > 0 )
    {
        if(hp < attack)
        {
           while(attack > hp)
               attack -= 2;
        }
        hp -= attack;
        answer++;
    }
    return answer;
}