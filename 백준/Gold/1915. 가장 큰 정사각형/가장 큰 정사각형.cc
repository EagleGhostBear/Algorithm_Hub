    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>
    #include <queue>
    #include <string>
    #include <cmath>

    using namespace std;

    typedef long long ll;

    int n, m, ans = 0;
    vector<vector<int>> dp; // dp[row][col] = 만들수 있는 정사각형 길이

    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        cin >> n >> m;
        dp.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) dp[i][j] = s[j] - '0';
        }
        for (int i = 0; i < n; i++) ans = max(ans, dp[i][0]);
        for (int j = 0; j < m; j++) ans = max(ans, dp[0][j]);

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (dp[i][j]) {
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans * ans;
    }