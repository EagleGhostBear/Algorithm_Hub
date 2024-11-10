#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
int INF = 1e9;

int n;
vector<vector<int>> cost; // cost[from 도시][to 도시] = 비용

// dp[도시 방문 여부 비트마스크][현재 도시 idx] = 경우의 수 (65536*16)
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cost.resize(n, vector<int>(n));
    dp.resize((1 << n), vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    dp[1][0] = 0;

    for (int visit = 1; visit < (1 << n); visit++) {
        for (int cur = 0; cur < n; cur++) { // 현재 방문한 도시 idx
            if (!(visit & (1 << cur))) { continue; } // 비트마스크에 cur(현재 방문 도시)가 없다면 continue
            int prev_visit = visit & ~(1 << cur);

            for (int prev = 0; prev < n; prev++) { // cur 방문하기전에 어떤값을 들고와야 할지 결정
                if (!(prev_visit & (1 << prev))) { continue; }
                if (!cost[prev][cur]) { continue; }
                dp[visit][cur] = min(dp[visit][cur], dp[prev_visit][prev] + cost[prev][cur]);
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (cost[i][0]) { // 마지막에 출발점으로 돌아갈 수 있는 경우만 고려 // 고려하지 않으면 갈 수 없음에도 최소로 계산이 시행된다.
            ans = min(ans, dp[(1 << n) - 1][i] + cost[i][0]);
        }
    }

    cout << ans;
}
// 모든 도시를 방문해야함
// 한번 방문했던 도시를 다시 방문 불가능
// 마지막으로 시작도시로 다시 돌아와야함