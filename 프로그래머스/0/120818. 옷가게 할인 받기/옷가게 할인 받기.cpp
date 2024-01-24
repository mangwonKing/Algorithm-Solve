#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    double dis = 0;
    if(price >= 100000 && price < 300000)
    {
        dis = price * 0.05;
    }
    else if(price >= 300000 && price < 500000)
    {
        dis = price * 0.1;
    }
    else if(price >= 500000)
    {
        dis = price * 0.2;
    }
    price -= dis;
    return price;
}