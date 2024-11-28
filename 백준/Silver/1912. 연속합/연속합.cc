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

int n;
vector<int> v;
vector<int> dp; // dp[idx] = 연속 수열의 합

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    dp.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dp[0] = v[0];
    int ans = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + v[i], v[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans;
}