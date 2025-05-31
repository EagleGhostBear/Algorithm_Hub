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

struct node {
    int row;
    int col;
    int k; // 나이트 이동 가능 회수
};

int k, w, h;
vector<vector<int>> v;
vector<vector<vector<int>>> visited; // visited[row][col][k] = 최소 이동회수

void bfs() {
    queue<node> q;
    q.push({ 0, 0, k });
    visited[0][0][k] = 0;

    int dr[] = { -1, 0, 1, 0, -2, -2, -1, 1, 2, 2, 1, -1 };
    int dc[] = { 0, 1, 0, -1, -1, 1, 2, 2, 1, -1, -2, -2 };
    while (q.size()) {
        node now = q.front(); q.pop();
        if (now.row == h - 1 && now.col == w - 1) return;

        for (int i = 0; i < 12; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= h || nc >= w || v[nr][nc]) continue;

            if (i < 4) {
                if (visited[nr][nc][now.k] <= visited[now.row][now.col][now.k] + 1) continue;
                visited[nr][nc][now.k] = visited[now.row][now.col][now.k] + 1;
                q.push({ nr, nc, now.k });
            }
            else { // 나이트 이동을 사용할 경우
                if (!now.k || visited[nr][nc][now.k - 1] <= visited[now.row][now.col][now.k] + 1) continue;
                visited[nr][nc][now.k - 1] = visited[now.row][now.col][now.k] + 1;
                q.push({ nr, nc, now.k - 1 });
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k >> w >> h;
    v.resize(h, vector<int>(w));
    visited.resize(h, vector<vector<int>>(w, vector<int>(k + 1, 1e9)));
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> v[i][j];

    bfs();

    int ans = 1e9;
    for (int i = 0; i <= k; i++) ans = min(ans, visited[h - 1][w - 1][i]);
    if (ans == 1e9) cout << -1;
    else cout << ans;
}