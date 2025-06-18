#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> v;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    double prev = k;
    int now = k;
    while(now > 1){
        if(now%2){ // 홀수
            now *= 3;
            now += 1;
        }
        else now /= 2;
        v.push_back((prev + now) / 2);
        prev = now;
    }
    int sz = v.size();
    for(int i=0; i<ranges.size(); i++){
        int from = ranges[i][0];
        int to = sz + ranges[i][1];
        if(from <= to){
            double tmp = 0;
            for(int j=from; j<to; j++) tmp += v[j];
            answer.push_back(tmp);
        }
        else answer.push_back(-1);
    }
    return answer;
}