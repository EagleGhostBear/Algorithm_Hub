#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

ll t, n, m, total = 0;
vector<vector<int>> dp(31, vector<int>(31, 1)); // dp[n][m] = 놓을수 있는 다리 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // dp[n][m] = dp[n][m-1] *m /(m-n)
    for (int i = 1; i <= 30; i++) {
        for (int j = i + 1; j <= 30; j++) {
            dp[i][j] = dp[i][j - 1] * j / (j - i);
        }
    }

    cin >> t;
    for (int k = 0; k < t; k++) {
        total = 0;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
}
/*
m!
(m-n)!n!
ex)
8 10
9*10
2!

8 11
9*10*11
3!
-> dp[n][m] = dp[n][m+1] *m /(m-n)
*/