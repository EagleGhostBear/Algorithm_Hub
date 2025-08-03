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
    int row, col, sz;
};

int n, m, k, ans = 6000;
vector<vector<int>> v;
vector<node> rt;

int calculate() {
    int tmp = 6000;
    for (int i = 0; i < n; i++) {
        int now = 0;
        for (int j = 0; j < m; j++) now += v[i][j];
        tmp = min(tmp, now);
    }
    return tmp;
}

void rotate_board(int idx, int type) {
    node r = rt[idx];
    // 좌측 상단 시작 // dr[0], dc[0] = 시계 | dr[1], dc[1] = 반시계
    int dr[2][4] = { {0, 1, 0, -1},{1, 0, -1, 0} };
    int dc[2][4] = { {1, 0, -1, 0},{0, 1, 0, -1} };
    for (int l = 1; l <= r.sz; l++) {
        pair<int, int> now = { r.row - l, r.col - l };
        queue<int> q;
        q.push(v[now.first][now.second]);
        int limit = 2 * l + 1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < limit - 1; j++) {
                int nr = now.first + dr[type][i];
                int nc = now.second + dc[type][i];
                q.push(v[nr][nc]);
                v[nr][nc] = q.front();
                q.pop();
                now = { nr, nc };
            }
        }
    }
    return;
}

void dfs(int bitmask) {
    if (bitmask == (1 << k) - 1) {
        ans = min(ans, calculate());
        return;
    }

    for (int i = 0; i < k; i++) {
        if (bitmask & (1 << i)) continue;
        rotate_board(i, 0);
        dfs(bitmask | (1 << i));
        rotate_board(i, 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];
    for (int i = 0; i < k; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        rt.push_back({ a - 1, b - 1, c });
    }

    dfs(0);

    cout << ans;
}