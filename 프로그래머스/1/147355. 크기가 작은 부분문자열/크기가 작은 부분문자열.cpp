#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

int solution(string t, string p) {
    int answer = 0;
    int sz = p.size();
    for(int i=0; i + sz <= t.size(); i++){
        ull left = stoull(t.substr(i, sz));
        ull right = stoull(p);
        if(right >= left) answer++;
    }
    return answer;
}