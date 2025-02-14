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
vector<vector<int>> dp; // dp[자리][0, 1] = 경우의 수
// dp[][0] = 0
// dp[][1] = 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (i - 2 >= 0) dp[i][0] += (dp[i - 2][0] + dp[i - 2][1]) % 15746;
        dp[i][1] += (dp[i - 1][0] + dp[i - 1][1]) % 15746;
    }

    cout << (dp[n][0] + dp[n][1]) % 15746;
}
/*
사용 가능 타일 2종류 00, 1
*/