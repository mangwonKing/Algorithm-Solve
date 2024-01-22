#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int size = 6;
    int cnt = n;
    while(1)
    {
        if(cnt == size)break;
        else if(cnt > size)
        {
            size += 6;
            
        }
        else if(cnt < size)
        {
            cnt += n;
        }
    }
    return size / 6;
}