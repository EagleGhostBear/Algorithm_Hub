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
};

int n, m, k;
vector<vector<int>> v;
vector<vector<vector<int>>> visited;

void bfs() {
    queue<node> q;
    q.push({ 0, 0, k });

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        node now = q.front(); q.pop();
        
        if (now.row == n - 1 && now.col == m - 1) continue;

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            
            if (v[nr][nc] && now.k && visited[nr][nc][now.k - 1] > visited[now.row][now.col][now.k] + 1) {
                visited[nr][nc][now.k - 1] = visited[now.row][now.col][now.k] + 1;
                q.push({ nr, nc, now.k - 1 });
            }
            if (!v[nr][nc] && visited[nr][nc][now.k] > visited[now.row][now.col][now.k] + 1) {
                visited[nr][nc][now.k] = visited[now.row][now.col][now.k] + 1;
                q.push({ nr, nc, now.k });
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    v.resize(n, vector<int>(m));
    visited.resize(n, vector<vector<int>>(m, vector<int>(k + 1, 1e9)));
    visited[0][0][k] = 1;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) v[i][j] = s[j] - '0';
    }

    bfs();

    int ans = 1e9;
    for (int i = 0; i <= k; i++) ans = min(ans, visited[n - 1][m - 1][i]);
    if (ans == 1e9) cout << "-1";
    else cout << ans;
}