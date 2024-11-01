#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int t, n;
vector<int> coin = { 1, 2, 3 };
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n; // 목표 값
        dp.clear();
        dp.resize(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i - coin[j] >= 0) {
                    dp[i] += dp[i - coin[j]];
                }
            }
        }

        cout << dp[n] << "\n";
    }
}