#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<int> v;
vector<vector<int>> dp; // dp[계단 번호][연속해서 밟은 계단수]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n+1, 0);
    dp.resize(n + 1, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int stair = 1; stair <= n; stair++) {
        if (stair < 2) {
            dp[stair][0] = v[stair];
        }
        else {
            // 연속해서 밟은 계단 수 = 1
            dp[stair][0] = max(dp[stair - 2][0] + v[stair], dp[stair - 2][1] + v[stair]);
            // 연속해서 밟은 계단 수 = 2
            dp[stair][1] = dp[stair - 1][0] + v[stair];
        }
    }

    cout << max(dp[n][0], dp[n][1]);
}
// 계단은 1단계 or 2단계 씩 오를 수 있다.
// 연속된 3개를 밟으면 안된다 -> 1,1 불가
// 시작은 바닥부터
// 마지막은 반드시 밟아야 한다.