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

int t, k, n;
vector<vector<int>> v;
vector<vector<int>> dp; // dp[층][호수]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    v.resize(15, vector<int>(15, 0));
    dp.resize(15, vector<int>(15, 0));
    for (int i = 1; i <= 14; i++) v[0][i] = i, dp[0][i] = dp[0][i - 1] + i;

    for (int f = 1; f <= 14; f++) {
        for (int h = 1; h <= 14; h++) {
            v[f][h] = dp[f - 1][h];
            dp[f][h] = dp[f][h-1] + v[f][h];
        }
    }

    while (t--) {
        cin >> k >> n;
        cout << v[k][n] << "\n";
    }
}