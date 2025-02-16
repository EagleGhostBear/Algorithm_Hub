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
vector<vector<int>> dp; // dp[자리수][0 - 9] = 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n + 1, vector<int>(10, 0));
    for (int i = 0; i < 10; i++) dp[1][i] = 1;

    for (int loc = 2; loc <= n; loc++) {
        for (int num = 0; num < 10; num++) {
            for (int i = 0; i <= num; i++) {
                if (dp[loc][num] + dp[loc - 1][i] > 10007) dp[loc][num] = (dp[loc][num] + dp[loc - 1][i]) % 10007;
                else dp[loc][num] += dp[loc - 1][i];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        if (ans + dp[n][i] > 10007) ans = (ans + dp[n][i]) % 10007;
        else ans += dp[n][i];
    }
    cout << ans;
}