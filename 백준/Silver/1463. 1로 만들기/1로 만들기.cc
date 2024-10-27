#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<int> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n+1, 1000000000);
    dp[1] = 0;

    for (int i = 2; i < n+1; i++) { // 1 -> n까지 찾아감
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0) { // 3의 배수일 경우 dp[i/3]을 가져오는게 이득인지 확인
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0) { // 2의 배수일 경우 dp[i/2]을 가져오는게 이득인지 확인
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[n];
}
// 3에 나눠지면 /3
// 2에 나눠지면 /2
// 1 빼기