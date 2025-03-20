#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;
const int MOD = 1000000003;

int n, k;
// N번째 색상 선택에 모든 색상 선택권을 소진 했을 경우
vector<vector<int>> dp; // dp[N번째 색][해당 색상에 올때까지 선택한 색상수] = 경우의 수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    dp.resize(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int color = 2; color <= n; color++) {
        for (int sel = 2; sel <= k; sel++) {
            // 현재 색상을 선택 안했을때 color - 1 경우의 수 그대로 받아옴
            // 현재 색상을 선택했다면 color - 2 에서 경우의 수를 받아옴
            dp[color][sel] = (dp[color - 1][sel] + dp[color - 2][sel - 1]) % MOD;
        }
    }
    // 1번을 선택O 경우(1번 선택O, N번 선택X, 2번 선택X = N-3의 색상에서 K-1개 선택)
    int ret1 = dp[n - 3][k - 1];

    // 1번을 선택X 경우(1번 선택O = N-1의 색상에서 K개 선택)
    int ret2 = dp[n - 1][k];

    cout << (ret1 + ret2) % MOD;
}
/*
점화식 : dp[color][sel] = dp[color - 1][sel] + dp[color - 2][sel - 1]
*/