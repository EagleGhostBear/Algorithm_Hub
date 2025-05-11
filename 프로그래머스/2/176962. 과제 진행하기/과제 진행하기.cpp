#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int convert(string time){
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3));
    return h * 60 + m;
}

struct compare{
    bool operator()(vector<string> left, vector<string> right){
        return convert(left[1]) < convert(right[1]);
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string, int>> work;
    sort(plans.begin(), plans.end(), compare());
    
    int prev_time = 0;
    // work.push_back({plans[0][0], stoi(plans[0][2])});
    for(int i=0; i<plans.size(); i++){
        // 현재 시각
        int now_time = convert(plans[i][1]);
        int avail_time = now_time - prev_time;
        while(avail_time && work.size()){
            if(work.back().second > avail_time){
                work.back().second -= avail_time;
                break;
            }
            else{
                avail_time -= work.back().second;
                answer.push_back(work.back().first);
                work.pop_back();
            }
        }
        prev_time = now_time;
        work.push_back({plans[i][0], stoi(plans[i][2])});
    }
    while(work.size()){
        answer.push_back(work.back().first);
        work.pop_back();
    }
    return answer;
}
/*
새로운게 들어오면 무조건 새로운거 부터
멈춘것중에서는 가장 최근에 멈춘것부터 시작(stack)
과제를 끝낸 순서대로 return
700(30분) 730(20분) 750(40분)
*/