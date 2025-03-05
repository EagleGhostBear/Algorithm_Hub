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
vector<int> dp; // dp[돌개수] = 이기는 사람

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n+1, 0);
    dp[1] = 1; dp[3] = 1, dp[4] = 1;
    dp[2] = 2;

    // 상근 -> 창영
    for (int i = 5; i <= n; i++) {
        if (dp[i - 1] == 2 || dp[i - 3] == 2 || dp[i - 4] == 2) dp[i] = 1;
        else dp[i] = 2;
    }

    if (dp[n] == 1) cout << "SK";
    else cout << "CY";
}