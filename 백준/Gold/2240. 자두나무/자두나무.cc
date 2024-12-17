#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t, w;
vector<vector<vector<int>>> dp; // dp[시간][위치][움직일 수 있는 회수] = 받는 자두 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t >> w;
    dp.resize(t+1, vector<vector<int>>(2, vector<int>(w + 1, -2000)));
    dp[0][0][w] = 0; // 1번 나무에 위치

    for (int i = 1; i < t+1; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 0; j < w + 1; j++) {
            dp[i][0][j] = dp[i - 1][0][j];
            dp[i][1][j] = dp[i - 1][1][j];
            if (tmp == 1) { // 1번 나무에서 열매가 떨어질 때
                if(j) {
                    // i-1 시간에서 w를 1 소모해서 받는 경우
                    dp[i][0][j - 1] = max(dp[i][0][j - 1], dp[i - 1][1][j] + 1);
                }
                // 그대로 기다려서 습득하는 법
                dp[i][0][j] = max(dp[i][0][j], dp[i - 1][0][j] + 1);
            }
            else if (tmp == 2) {
                if(j) {
                    // i-1 시간에서 w를 1 소모해서 받는 경우
                    dp[i][1][j - 1] = max(dp[i][1][j - 1], dp[i - 1][0][j] + 1);
                }
                // 그대로 기다려서 습득하는 법
                dp[i][1][j] = max(dp[i][1][j], dp[i - 1][1][j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < w + 1; j++) {
            ans = max(ans, dp[t][i][j]);
        }
    }

    cout << ans;
}