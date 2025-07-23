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

struct node {
    int row, col, dis;
};

int n, m, d, ans = 0;
vector<vector<int>> v;

void solution(vector<int> archer) {
    vector<vector<int>> board = v;

    int cnt = 0;
    int dr[] = {0, -1, 0};
    int dc[] = {-1, 0, 1};
    while (board.size()) {
        int h = board.size();
        unordered_map<int, bool> um;
        for (auto idx : archer) {
            queue<node> q;
            q.push({ h, idx, d });

            bool chk = false;
            while (q.size() && q.front().dis) {
                node now = q.front();
                q.pop();

                for (int i = 0; i < 3; i++) {
                    int nr = now.row + dr[i];
                    int nc = now.col + dc[i];
                    if (nr < 0 || nc < 0 || nr >= h || nc >= m) continue;

                    if (board[nr][nc]) {
                        um[nr * m + nc] = true;
                        chk = true;
                        break;
                    }
                    else q.push({ nr, nc, now.dis - 1 });
                }
                if (chk) break;
            }
        }
        for (auto data : um) if (data.second) {
            cnt++;
            board[data.first / m][data.first % m] = 0;
        }
        board.pop_back();
    }
    ans = max(ans, cnt);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> d;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

    for (int i = 0; i < m; i++) for (int j = i + 1; j < m; j++) for (int k = j + 1; k < m; k++) {
        solution({ i, j, k });
    }

    cout << ans;
}