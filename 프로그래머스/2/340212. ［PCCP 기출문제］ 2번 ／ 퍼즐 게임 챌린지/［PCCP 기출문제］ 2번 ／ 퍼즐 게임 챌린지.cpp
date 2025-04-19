#include <string>
#include <vector>
#include <iostream>

typedef long long ll;

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    ll ans = 100000;
    ll left = 1;
    ll right = 100000;
    ll level;
    while(left <= right){
        ll total = 0;
        level = (left + right) / 2;
        
        // 해당 숙련도로 시간 계산
        for(int i=0; i<diffs.size(); i++){
            if(total > limit) break;
            int diff = diffs[i];
            if(diff > level){
                ll loop = diff - level;
                ll one_time = times[i] + times[i - 1];
                total += one_time * loop;
            }
            total += times[i];
        }
        // cout << "level: " << level << " time: " << total << "\n";
        
        if(total > limit){
            left = level + 1;
        }
        else{
            ans = min(ans, level);
            right = level - 1;
        }
    }
    return ans;
}
/*
diff : 난이도
time_cur : 현재 퍼즐 소요시간
time_prev : 이전 퍼즐 소요시간
leve : 나의 숙련도

시간 내에 퍼즐을 모두 해결하기 위한 순련도의 최솟값
*/