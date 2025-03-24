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

int n, m, cnt = 0;
vector<vector<int>> v;
vector<vector<int>> visited;
queue<pair<int, int>> q;

void melt(int row, int col) {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
        if (!v[nr][nc] && v[row][col] && visited[nr][nc] < visited[row][col]) v[row][col]--;
    }
    if (!v[row][col]) cnt--;
}

int solution() {
    int ret = 0;
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        pair<int, int> now = q.front(); q.pop();

        ret++;
        melt(now.first, now.second);

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (!v[nr][nc]) continue;
            if (visited[nr][nc] >= visited[now.first][now.second]) continue;

            visited[nr][nc]++;
            q.push({ nr, nc });
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> v[i][j];
        if (v[i][j]) cnt++;
        if (q.empty() && v[i][j]) q.push({i, j}), visited[i][j]++;
    }

    int ans = 0;
    while (cnt) {
        ans++;
        for (int i = 0; i < n * m; i++) {
            int row = i / m, col = i % m;
            if (q.empty() && v[row][col]) {
                q.push({ row, col });
                visited[row][col]++;
                break;
            }
        }
        int prev = cnt;
        int next = solution();
        if (prev != next) {
            cout << ans - 1;
            return 0;
        }
    }

    cout << "0";
}