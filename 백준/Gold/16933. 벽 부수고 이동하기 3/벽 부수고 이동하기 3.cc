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
    int k;
    bool time; // false : 밤, true : 낮
};

int n, m, k;
int ans = 1e9;
int v[1001][1001];
// visited[row][col][k][낮,밤] 20,000,000
int visited[1001][1001][11][2] = { 0, };

void bfs() {
    queue<node> q;
    q.push({ 0, 0, k, true });
    visited[0][0][k][1] = 1;

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        node now = q.front(); q.pop();

        if (now.row == n - 1 && now.col == m - 1) {
            ans = min(ans, visited[now.row][now.col][now.k][now.time]);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

            // 벽뚫기
            if (v[nr][nc] && now.time && now.k && visited[nr][nc][now.k - 1][!now.time] == 0) {
                visited[nr][nc][now.k - 1][!now.time] = visited[now.row][now.col][now.k][now.time] + 1;
                q.push({ nr, nc, now.k - 1, !now.time });
            }
            // bfs이동
            if (!v[nr][nc] && visited[nr][nc][now.k][!now.time] == 0) {
                visited[nr][nc][now.k][!now.time] = visited[now.row][now.col][now.k][now.time] + 1;
                q.push({ nr, nc, now.k, !now.time });
            }
        }
        if (!now.time && visited[now.row][now.col][now.k][!now.time] == 0) {
            visited[now.row][now.col][now.k][!now.time] = visited[now.row][now.col][now.k][now.time] + 1;
            q.push({ now.row, now.col, now.k, !now.time });
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) v[i][j] = s[j] - '0';
    }

    bfs();

    if (ans == 1e9) cout << "-1";
    else cout << ans;
}