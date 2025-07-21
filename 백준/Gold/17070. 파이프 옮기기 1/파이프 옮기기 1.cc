#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> v;
vector<vector<vector<int>>> dp; // dp[row][col][가로, 대각선, 세로]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    dp.resize(n, vector<vector<int>>(n, vector<int>(3)));
    dp[0][1][0] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j]) continue;
            if (j - 1 >= 0) dp[i][j][0] += (dp[i][j - 1][0] + dp[i][j - 1][1]); // 가로
            if (i - 1 >= 0) dp[i][j][2] += (dp[i - 1][j][1] + dp[i - 1][j][2]); // 세로
            if (i - 1 >= 0 && j - 1 >= 0 && !v[i-1][j] && !v[i][j-1]) dp[i][j][1] += (dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]);
        }
    }
    cout << (dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2]);
}