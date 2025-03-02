#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, k;
vector<int> coin;
vector<int> dp; // dp[금액] = 최소 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    coin.resize(n);
    dp.resize(k + 1, 1e9);
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) cin >> coin[i];

    for (int i = 0; i < n; i++) for (int cost = 1; cost <= k; cost++) {
        if (cost - coin[i] >= 0) dp[cost] = min(dp[cost], dp[cost - coin[i]] + 1);
    }

    if (dp[k] == 1e9) cout << "-1";
    else cout << dp[k];
}