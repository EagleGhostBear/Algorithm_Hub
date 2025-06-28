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

int n, m;
vector<vector<vector<pair<int, int>>>> btn;
int light[100][100]; // v[row][col] = 불 켜짐 여부
int visited[100][100]; // v[row][col] = 불 켜짐 여부

pair<int, int> is_side(int row, int col) {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        if (visited[nr][nc]) return {nr, nc};
    }
    return {-1, -1};
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (q.size()) {
        pair<int, int> now = q.front();
        q.pop();

        // 들어온 방에서 켤수 있는 방은 다 켠다.
        for (auto data : btn[now.first][now.second]) { // 불이 들어온방이 갈 수 있는 루트이면 추가
            light[data.first][data.second] = 1;
            if (!visited[data.first][data.second]) {
                pair<int, int> tmp = is_side(data.first, data.second);
                if (tmp.first != -1 || tmp.second != -1) q.push(tmp);
            }
        }

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n || !light[nr][nc] || visited[nr][nc]) continue;

            // 불켜져있고 한번도 방문한적 없는방
            visited[nr][nc] = 1;
            q.push({ nr, nc });
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    btn.resize(n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>()));
    light[0][0] = 1;
    visited[0][0] = 1;
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        btn[a - 1][b - 1].push_back({ c - 1, d - 1 });
    }

    bfs();

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (light[i][j]) ans++;
    cout << ans;
}
/*
들어갈 수 있는 방 X -> 불켜진 방의 수
*/