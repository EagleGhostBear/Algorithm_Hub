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

int n, m, ans = 1e9;
vector<vector<int>> v, board;
vector<vector<int>> bridge; // dridge[from][to] = 다리 길이

void set_color(int row, int col, int color) {
    queue<pair<int, int>> q;
    q.push({ row, col });

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (v[nr][nc] == 0) continue;
            v[nr][nc] = 0;
            board[nr][nc] = color;
            q.push({ nr, nc });
        }
    }
    return;
}

void set_bridge(int row, int col, int color, int dir) {
    int cnt = 0;
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (board[row][col] == 0) {
        row += dr[dir];
        col += dc[dir];
        if (row < 0 || col < 0 || row >= n || col >= m) return;
        cnt++;
    }
    int next_color = board[row][col];
    if (next_color != color && cnt > 1) {
        if (bridge[color][next_color]) bridge[color][next_color] = min(bridge[color][next_color], cnt);
        else bridge[color][next_color] = cnt;
    }
    return;
}

void bfs(int row, int col, int color) {
    queue<pair<int, int>> q;
    q.push({ row, col });

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (v[nr][nc]) continue;

            if (board[nr][nc]) {
                v[nr][nc] = 1;
                q.push({ nr, nc });
            }
            else {
                set_bridge(nr, nc, color, i);
            }
        }
    }
    return;
}

void solution(int visited, int total, vector<int> distance) {
    if (visited == (1 << bridge.size()) - 2) {
        ans = min(ans, total);
        return;
    }

    for (int i = 2; i < bridge.size(); i++) {
        if (visited & (1 << i)) continue;
        if (distance[i] == 0) continue;
        vector<int> tmp = distance;
        for (int j = 0; j < tmp.size(); j++) {
            if (bridge[i][j] == 0) continue;
            if (tmp[j]) tmp[j] = min(tmp[j], bridge[i][j]);
            else tmp[j] = bridge[i][j];
        }
        solution(visited | (1 << i), total + distance[i], tmp);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    board.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

    int color = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (v[i][j]) {
            v[i][j] = 0;
            board[i][j] = color;
            set_color(i, j, color++);
        }
    }
    bridge.resize(color, vector<int>(color));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (board[i][j] && v[i][j] == 0) {
            v[i][j] = 1; // v 를 visited로 재활용
            bfs(i, j, board[i][j]);
        }
    }

    solution((1 << 1), 0, bridge[1]);

    if (ans == 1e9) cout << "-1";
    else cout << ans;
}
/*
*/