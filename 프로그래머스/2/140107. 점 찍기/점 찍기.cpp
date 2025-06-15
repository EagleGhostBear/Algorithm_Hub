#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

long long solution(int k, int d) {
    long long answer = 0;
    ll dd = pow(d, 2);
    for(ll y=0; y<=d; y+=k){
        ll x = sqrt(dd - pow(y, 2));
        answer += (x/k + 1);
    }
    return answer;
}