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

int n;
vector<vector<int>> dp; // dp[N번째 자리][0 ~ 9] = 개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n + 1, vector<int>(10, 0));

    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j - 1 >= 0) {
                dp[i][j] += dp[i-1][j - 1];
            }
            if (j + 1 <= 9) {
                dp[i][j] += dp[i-1][j + 1];
            }
            if (dp[i][j] > 1000000000) {
                dp[i][j] %= 1000000000;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[n][i];
        if (ans > 1000000000) {
            ans %= 1000000000;
        }
    }

    cout << ans;
}