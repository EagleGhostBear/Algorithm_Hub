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
vector<int> cost;
vector<int> dp; // dp[카드 개수] = 최대 비용

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cost.resize(n + 1);
    dp.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> cost[i];

    for (int cnt = 1; cnt <= n; cnt++) {
        for (int idx = 1; idx <= n; idx++) {
            if (cnt - idx < 0) continue;
            dp[cnt] = max(dp[cnt], dp[cnt - idx] + cost[idx]);
        }
    }

    cout << dp[n];
}
/*
돈을 최대한 많이 써서 N개 구입
*/