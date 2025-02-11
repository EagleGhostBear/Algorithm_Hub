#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;


int t, n;
vector<int> dp(1000001, 0); // dp[총합] = 방법의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    for (int i = 1; i <= 1000000; i++) {
        if (i - 1 > -1) dp[i] += dp[i - 1];
        if (dp[i] > 1000000009) dp[i] %= 1000000009;
        if (i - 2 > -1) dp[i] += dp[i - 2];
        if (dp[i] > 1000000009) dp[i] %= 1000000009;
        if (i - 3 > -1) dp[i] += dp[i - 3];
        if (dp[i] > 1000000009) dp[i] %= 1000000009;
    }

    while (t--) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}