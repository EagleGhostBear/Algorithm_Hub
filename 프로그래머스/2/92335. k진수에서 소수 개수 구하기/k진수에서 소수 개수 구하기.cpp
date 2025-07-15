#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

bool is_chk(string s){
    if(s.empty()) return false;
    ll num = stoll(s);
    if(num == 1) return false;
    for(ll i=2; i<=sqrt(num); i++) if(num % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string s = "";
    while(n > 0){
        s = to_string(n%k) + s;
        n /= k;
    }
    string tmp;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
            if(is_chk(tmp)) answer++;
            tmp = "";
        }
        else tmp += s[i];
    }
    if(is_chk(tmp)) answer++;
    return answer;
}