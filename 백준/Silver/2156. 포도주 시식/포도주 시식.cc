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
vector<int> v;
vector<vector<int>> dp; // dp[포도주 idx][연속 개수(0, 1, 2)] = 총 포도주

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n+1);
    dp.resize(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) cin >> v[i];
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
        dp[i][1] = max(dp[i][1], dp[i - 1][0] + v[i]);
        dp[i][2] = max(dp[i][2], dp[i - 1][1] + v[i]);
    }

    int ans = 0;
    for (int i = 0; i < 3; i++) ans = max(ans, dp[n][i]);
    cout << ans;
}