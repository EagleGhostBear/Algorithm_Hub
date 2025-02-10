#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

int t, n, m;
string s;
vector<vector<int>> dp; // dp[열][행 비트마스크] = 배치 가능한 경우의 수
vector<vector<int>> chair; // 부서진 좌석 표시

int mask_cnt(int mask) {
    int ret = 0;
    for (int i = 0; i < m; i++) if (mask & (1 << i)) ret++;
    return ret;
}

bool is_safe(int row, int prev_mask, int curr_mask) {
    for (int col = 0; col < m; col++) {
        if (curr_mask & (1 << col)) {
            // 의자가 부셔진 위치
            if (chair[row][col]) return false;

            // 컨닝 가능 위치 확인
            // 왼쪽 대각선 위
            if (0 < col && prev_mask & (1 << col - 1)) return false;
            // 오른쪽 대각선 위
            if (col < m-1 && prev_mask & (1 << col + 1)) return false;
            
            // 왼쪽
            if (0 < col && curr_mask & (1 << col - 1)) return false;
            // 오른쪽 생략(만약 오른쪽에 있다면 그 다음 반복문에서 걸릴것이다)
        }
    }
    return true;
}

void solution() {
    for (int i = 1; i <= n; i++) {
        for (int prev_mask = 0; prev_mask < (1 << m); prev_mask++) {
            if (dp[i - 1][prev_mask] == -1) continue;

            for (int curr_mask = 0; curr_mask < (1 << m); curr_mask++) {
                if (!is_safe(i, prev_mask, curr_mask)) continue; // 조건 확인
                dp[i][curr_mask] = max(dp[i][curr_mask], dp[i - 1][prev_mask] + mask_cnt(curr_mask));
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        chair.clear(); dp.clear();
        chair.resize(n+1, vector<int>(m, 0));
        dp.resize(n+1, vector<int>(1 << m, -1)); // dp 편의성을 위해 row = 1부터 시작
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            for (int j = 0; j < s.size(); j++) if (s[j] == 'x') chair[i][j] = 1;
        }

        solution();

        int ans = 0;
        for (int i = 0; i < (1 << m); i++) ans = max(ans, dp[n][i]);
        cout << ans << "\n";
    }
}