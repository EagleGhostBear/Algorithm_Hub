#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<ll> dp; // dp[n번째 칸] = 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n+1);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * 2;
        dp[i] %= 10007;
    }

    cout << dp[n];
}
// s(n) = s(n-1)*1 + s(n-2)*2