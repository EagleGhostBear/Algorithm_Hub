#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n / a){
        int gain = (n/a)*b;
        answer += gain;
        n %= a;
        n += gain;
    }
    return answer;
}