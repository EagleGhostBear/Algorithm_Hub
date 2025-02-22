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
vector<int> dp; // dp[숫자] = 최소항
vector<int> pow_num;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= 316; i++) pow_num.push_back(pow(i, 2));

    for (int i = 0; i <= n; i++) { // 100,000 * 316
        int left = 1, right = 316; // 316^2 = 99,856
        for (int idx = 0; idx < 316; idx++) {
            if (i - pow_num[idx] > -1) dp[i] = min(dp[i], dp[i - pow_num[idx]] + 1);
            else break;
        }
    }

    cout << dp[n];
}