#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string s;
    while(n > 0) {
        s += to_string(n % 3);
        n /= 3;
    }
    int num = 1;
    for(int i=s.size()-1; i>-1; i--){
        answer += (s[i] - '0') * num;
        num *= 3;
    }
    return answer;
}