#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> color;
vector<vector<int>> dp; // dp[집번호][집색깔]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    color.resize(n+1, vector<int>(3));
    dp.resize(n+1, vector<int>(3));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1] + color[i][0], dp[i - 1][2] + color[i][0]);
        dp[i][1] = min(dp[i - 1][0] + color[i][1], dp[i - 1][2] + color[i][1]);
        dp[i][2] = min(dp[i - 1][0] + color[i][2], dp[i - 1][1] + color[i][2]);
    }

    int minv = dp[n][0];
    minv = min(minv, dp[n][1]);
    minv = min(minv, dp[n][2]);
    cout << minv;
}
// N-1번, N번, N+1번 집의 색깔은 달라야 한다.
// 각 집의 빨, 초, 파 로 칠하는 비용이 다를 때 최솟값