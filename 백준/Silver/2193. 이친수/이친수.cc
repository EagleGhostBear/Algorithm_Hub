#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<vector<ll>> dp; // dp[자리수][0인지 1인지] = 개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n + 1, vector<ll>(2, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] += (dp[i - 1][0] + dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0]+dp[n][1];
}
// 무조건 1로 시작
// 1이 연속되서 2번 등장 불가 ex) 11