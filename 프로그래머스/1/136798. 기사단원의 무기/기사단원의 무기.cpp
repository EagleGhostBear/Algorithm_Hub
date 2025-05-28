#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> v(100001, 1);

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=2; i<=100000; i++){
        for(int j=1; i*j<=100000; j++){
            v[i*j]++;
        }
    }
    for(int i=1; i<=number; i++){
        if(v[i] > limit) answer += power;
        else answer += v[i];
    }
    return answer;
}