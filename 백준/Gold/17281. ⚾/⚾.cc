#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, ans = 0;
vector<int> lineup(9);
vector<vector<int>> board;

int solution() {
    int score = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        queue<int> cnt;
        int out_cnt = 0;
        for (int l = 0; l < 3; l++) cnt.push(0);
        while (out_cnt < 3) {
            int now_num = lineup[idx++];
            if (idx > 8) idx = 0;

            if (board[i][now_num]) {
                int run_cnt = 0;
                if (board[i][now_num] == 1) run_cnt = 0;
                else if (board[i][now_num] == 2) run_cnt = 1;
                else if (board[i][now_num] == 3) run_cnt = 2;
                else if (board[i][now_num] == 4) run_cnt = 3;

                if (cnt.front()) score++;
                cnt.pop();
                cnt.push(1);
                while (run_cnt--) {
                    if (cnt.front()) score++;
                    cnt.pop();
                    cnt.push(0);
                }
            }
            else {
                if (++out_cnt == 3) break;
            }
        }
    }
    return score;
}

void dfs(int idx, int bitmask) {
    if (idx == 3) idx++; // 4번타자는 이미 확정이므로 넘어감
    if (idx == 9) {
        ans = max(ans, solution());
        return;
    }

    for (int num = 1; num < 9; num++) { // 2번타자 - 9번타자 까지
        if (bitmask & (1 << num)) continue;
        lineup[idx] = num;
        dfs(idx + 1, bitmask | (1 << num));
        lineup[idx] = -1;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    board.resize(n, vector<int>(9));
    for (int i = 0; i < n; i++) for (int j = 0; j < 9; j++) cin >> board[i][j];

    dfs(0, 1);
    cout << ans;
}