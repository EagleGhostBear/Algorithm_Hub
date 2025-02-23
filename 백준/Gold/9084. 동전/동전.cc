    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>
    #include <queue>
    #include <string>
    #include <cmath>

    using namespace std;

    typedef long long ll;

    int t, n, m;

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        cin >> t;
        while (t--) {
            cin >> n;
            vector<int> coin(n);
            for (int i = 0; i < n; i++) cin >> coin[i];
            cin >> m;
            vector<int> dp(m + 1, 0); // dp[금액] = 경우의 수
            dp[0] = 1;

            for (int i = 0; i < n; i++) {
                for (int cost = 0; cost <= m; cost++) {
                    if (cost - coin[i] < 0) continue;
                    dp[cost] += dp[cost - coin[i]];
                }
            }

            cout << dp[m] << "\n";
        }
    }