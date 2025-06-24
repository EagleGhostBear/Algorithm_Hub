#include <iostream>

using namespace std;

typedef long long ll;

long long solution(int price, int money, int count)
{
    ll answer = 0;
    for(ll i=1; i<=count; i++){
        answer += (price * i);
    }
    if(money >= answer) return 0;
    else return answer - money;
}