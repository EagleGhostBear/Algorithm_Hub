#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int t, n;
vector<ll> dp; // 해당 idx 삼각형 변의 길이

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    dp.resize(101);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i - 1] + dp[i - 5];
    }

    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        cout << dp[n] << "\n";
    }
}

// p(6) = p(5) + p(1)
// p(10) = p(9) + p(5)
// p(11) = p(10) + p(6)