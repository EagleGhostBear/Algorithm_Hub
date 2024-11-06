#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long ll;

int t, n;
vector<vector<ll>> dp(41, vector<ll>(2));

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp[0] = { 1, 0 };
    dp[1] = { 0, 1 };

    for (int i = 2; i <= 40; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        cout << dp[n][0] << " " << dp[n][1] << "\n";
    }
}