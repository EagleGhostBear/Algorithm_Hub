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
vector<int> dp; // dp[col] = 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n + 1, 0);
    dp[0] = 1;

    int cnt = 0;
    for (int col = 1; col <= n; col++) {
        // 1 * 2 블록 3개 쓰는 경우
        if (col - 2 >= 0) dp[col] += dp[col - 2];

        /*
         ㅡ ㅡ      ㅡㅡㅡ
        ㅣ = ㅣ -> ㅣ= =ㅣ 이런식으로 2칸식 늘어나는걸 감안
        */
        for (int i = col - 2; i > -1; i -= 2) {
            dp[col] += (dp[i] * 2);
        }
    }

    cout << dp[n];
}