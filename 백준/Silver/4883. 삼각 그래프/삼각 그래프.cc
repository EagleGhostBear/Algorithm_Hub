#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> cost;
vector<vector<int>> dp; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (cin >> n) {
        if (n == 0) break;

        cost.clear(); dp.clear();
        cost.resize(n, vector<int>(3));
        dp.resize(n, vector<int>(3, 1e9));
        for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> cost[i][j];
        dp[0][0] = 1e9; dp[0][1] = cost[0][1]; dp[0][2] = cost[0][2] + cost[0][1];

        // 같은 열도 확인해야함(같은 열이 - 가 큰 경우 거쳐오는게 이득일 수 있음)
        for (int row = 1; row < n; row++) { // 100,000
            for (int col = 0; col < 3; col++) {
                if (col - 1 > -1) {
                    dp[row][col] = min(dp[row][col], cost[row][col] + dp[row - 1][col - 1]);
                    // 같은 열 왼쪽에서는 받아올 수 있음
                    dp[row][col] = min(dp[row][col], cost[row][col] + dp[row][col - 1]);
                }
                dp[row][col] = min(dp[row][col], cost[row][col] + dp[row - 1][col]);
                if (col + 1 < 3) dp[row][col] = min(dp[row][col], cost[row][col] + dp[row - 1][col + 1]);
            }
        }

        cout << t << ". " << dp[n - 1][1] << "\n";
        t++;
    }
}