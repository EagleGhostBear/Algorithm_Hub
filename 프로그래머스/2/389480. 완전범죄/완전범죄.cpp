#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> dp; // dp[물건][B흔적] = A흔적 최소

int solution(vector<vector<int>> info, int n, int m) {
    int ans = 1e9;
    
    dp.resize(info.size(), vector<int>(m, 1e9));
    // A초기값 설정
    if(info[0][0] < n) dp[0][0] = info[0][0];
    // B초기값 설정
    if(info[0][1] < m) dp[0][info[0][1]] = 0;
    for(int idx=1; idx<info.size(); idx++){
        int val_a = info[idx][0];
        int val_b = info[idx][1];
        for(int b = 0; b < m; b++){
            if(idx - 1 >= 0){
                // A가 훔친 경우
                if(dp[idx - 1][b] + val_a < n){
                    dp[idx][b] = dp[idx - 1][b] + val_a;
                }
                if(b - val_b >= 0){
                    // B가 훔친 경우
                    dp[idx][b] = min(dp[idx][b], dp[idx - 1][b - val_b]);
                }
            }
        }
    }
    
    for(auto c : dp[info.size() - 1]){
        ans = min(ans, c);
    }
    if(ans == 1e9) ans = -1;
    return ans;
}