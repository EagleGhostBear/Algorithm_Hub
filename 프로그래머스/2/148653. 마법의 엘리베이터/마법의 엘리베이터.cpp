#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey){
        int now = storey % 10; // 4
        if(now < 5){
            answer += now;
            storey -= now;
        }
        else if(now > 5){
            answer += (10 - now);
            storey += (10 - now);
        }
        else{
            if(storey / 10 % 10 >= 5){
                answer += (10 - now);
                storey += (10 - now);
            }
            else{
                answer += now;
                storey -= now;
            }
        }
        storey /= 10;
    }
    return answer;
}
/*
제일 아래층 0
<- 5, 6 ->
5일때 내림, 올림 선택
그다음 자리가 6이상 일때는 올리는게 이득
*/