#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0; i<schedules.size(); i++){ // 출근시간(7시 ~ 11시)
        bool chk = true;
        int limit_time = (schedules[i]/100*60) + schedules[i]%100 + 10;
        for(int j=0; j<timelogs[i].size(); j++){
            if(startday++ > 5){
                if(startday > 7) startday = 1;
                continue;
            }
            int now_time = (timelogs[i][j]/100*60) + timelogs[i][j]%100;
            
            if(now_time <= limit_time) continue;
            else{
                cout << "false: " << timelogs[i][j] << "\n";
                chk = false;
            }
        }
        if(chk) answer++;
    }
    return answer;
}