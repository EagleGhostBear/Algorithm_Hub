#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> v;

ll convert_n(string s){ // 해당 자리수에서 계산하고 재귀로 받는 형식
    ll n = 0, cnt = 0;
    for(int i=s.size() - 1; i>-1; i--){
        n += (s[i] - 'a' + 1) * pow(26, cnt++);
    }
    return n;
}

string convert_s(ll n){ // 해당 자리수에서 계산하고 재귀로 받는 형식
    string s;
    while(n > 0){
        n--;
        s += ('a' + n % 26);
        n /= 26;
    }
    for(int i=0; i<s.size()/2; i++){
        char tmp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = tmp;
    }
    return s;
}

string solution(long long n, vector<string> bans) {
    ll del = 0;
    for(int i=0; i<bans.size(); i++){
        v.push_back(convert_n(bans[i]));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        if(n >= v[i] - del) del++;
    }
    return convert_s(n + del);
}
/*
그냥 27진법 숫자로 생각하면 안되나?
*/