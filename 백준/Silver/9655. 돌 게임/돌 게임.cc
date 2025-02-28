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
    vector<vector<int>> dp; // dp[뽑는 사람][돌 개수] = ?

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        cin >> n;
        dp.resize(2, vector<int>(n+1, 0));
        dp[1][0] = 1; // 상근이가 먼저 뽑으므로 창영이가 뽑은 설정

        // 상근 -> 창영
        for (int i = 1; i <= n; i++) {
            if (i - 1 >= 0) {
                dp[0][i] = dp[1][i - 1];
                dp[1][i] = dp[0][i - 1];
            }
            if (i - 3 >= 0) {
                dp[0][i] = dp[1][i - 3];
                dp[1][i] = dp[0][i - 3];
            }
        }

        if (dp[0][n]) cout << "SK";
        else cout << "CY";
    }
