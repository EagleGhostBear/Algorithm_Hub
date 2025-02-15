#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> v(2, vector<int>(n + 1));
        for (int i = 0; i < 2; i++) for (int j = 1; j <= n; j++) cin >> v[i][j];

        // dp[col][0 = 안땠다, 1 = row 1번 땜, 2 = row 2번 땜] = 최대 점수
        vector<vector<int>> dp(n+1, vector<int>(3, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
            
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + v[0][i]);
            dp[i][1] = max(dp[i][1], dp[i - 1][2] + v[0][i]);

            dp[i][2] = max(dp[i][2], dp[i - 1][0] + v[1][i]);
            dp[i][2] = max(dp[i][2], dp[i - 1][1] + v[1][i]);
        }

        int ans = 0;
        for (int i = 0; i < 3; i++) ans = max(ans, dp[n][i]);
        cout << ans << "\n";
    }
}