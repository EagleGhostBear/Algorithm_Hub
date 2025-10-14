#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> dp; // dp[시간][현재 온도] = 최소 전력

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    // 온도 범위를 -10 ~ 40 으로 잡고 모두 10 높여서 생각
    dp.assign(onboard.size(), vector<int>(51, 1e6));
    temperature += 10, t1 += 10, t2 += 10;
    dp[0][temperature] = 0;
    for(int i=1; i<dp.size(); i++){
        for(int j=0; j<51; j++){
            if(onboard[i] && (j < t1 || j > t2)) continue; // 승객이 있다면 다른 온도는 t1 - t2 범위 이해는 생각할 필요X
            // 에어컨 끔
            if(j == temperature) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if(j - 1 < temperature && j){ // 가만히 두면 온도 상승
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            if(j + 1 > temperature && j < 50){ // 가만히 두면 온도 하락
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
            }
            
            // 에어컨 켬, 희망 온도는 3종류(현재보다 낮게, 같게, 높게)
            if(j < 50) dp[i][j] = min(dp[i][j], dp[i - 1][j + 1] + a); // 낮게(온도 하락)
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + b); // 같게
            if(j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a); // 높게(온도 상승)
        }
    }
    int answer = 1e6;
    for(auto c : dp.back()) answer = min(answer, c);
    return answer;
}
/*
t1 : 희망 온도 min
t2 : 희망 온도 max
a  : 희망온도와 다를때 소비 전력
b  : 희망온도와 같을때 소비 전력
temperature : 실외 온도(고정)

실제로는 희망온도에 따라 -10 ~ 40 범위를 벗어날 수 있고 이 경우가 더 효율적이다?
"이전 단계 온도" 와 "희망 온도" 를 비교하는게 맞기 때문에 j - 1, j + 1 과 비교
*/