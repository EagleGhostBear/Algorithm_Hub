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

int n, ans = 1000;
vector<vector<int>> v;
vector<vector<pair<int, int>>> bridge;
queue<pair<int, int>> sea;

void init_num() {
    int team = 1;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    queue<pair<int, int>> q;
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (v[i][j] && !visited[i][j]) {
            visited[i][j] = 1;
            v[i][j] = team;
            q.push({ i, j });
            while (q.size()) {
                pair<int, int> now = q.front(); q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = now.first + dr[i];
                    int nc = now.second + dc[i];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= n || visited[nr][nc]) continue;

                    visited[nr][nc] = 1;
                    if (v[nr][nc]) v[nr][nc] = team, q.push({ nr, nc });
                    else {
                        bridge[nr][nc] = { team, 1 };
                        sea.push({ nr, nc });
                    }
                }
            }
            team++;
        }
    }
}

void find_bridge() {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    while (sea.size()) {
        pair<int, int> now = sea.front(); sea.pop();
        int row = now.first;
        int col = now.second;

        if (bridge[row][col].second >= ans) break;

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (v[nr][nc]) { // 육지에 도착했을때
                if (bridge[row][col].first == v[nr][nc]) continue;
                else ans = min(ans, bridge[row][col].second);
            }
            else { // 바다일때
                if (bridge[nr][nc].first == bridge[row][col].first) {
                    if (bridge[nr][nc].second <= bridge[row][col].second + 1) continue;
                }
                else if (bridge[nr][nc].first && bridge[nr][nc].first != bridge[row][col].first) {
                    ans = min(ans, bridge[row][col].second + bridge[nr][nc].second);
                    continue;
                }
                bridge[nr][nc].first = bridge[row][col].first;
                bridge[nr][nc].second = bridge[row][col].second + 1;
                sea.push({ nr, nc });
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    bridge.resize(n, vector<pair<int, int>>(n, { 0, 0 }));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    init_num();

    find_bridge();

    cout << ans;
}