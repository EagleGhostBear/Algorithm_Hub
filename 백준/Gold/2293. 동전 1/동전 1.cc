#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, k;
vector<int> coin;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k; // 1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000
    coin.resize(n);
    dp.resize(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for (int i = 0; i < n; i++) { // 동전 별로 계산
        for (int price = coin[i]; price <= k; price++) {
            dp[price] += dp[price - coin[i]];
        }
    }

    /*
    // 현재 코드에서 dp 배열을 갱신할 때, 모든 동전을 매번 순차적으로 고려하고 있습니다.
    // 예를 들어, 금액 3원을 만들 때 (1, 2)와 (2, 1)은 같은 구성인데도 불구하고 서로 다른 경우로 계산됩니다.
    // 이는 동전의 순서를 고려하지 않는 문제에서 의도하지 않은 중복을 발생시킵니다.
    for (int i = 1; i < k + 1; i++) { // 1,000,000
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0) { // 현재 가격 - 동전 금액
                dp[i] += dp[i - coin[j]];
                cout << i << ": " << i - coin[j] << "\n";
            }
        }
    }
    */

    cout << dp[k];
}