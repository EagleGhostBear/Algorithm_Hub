#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int t, n, m, k;
vector<vector<int>> v;
int cnt = 0;

void bfs(int row, int col) {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
            continue;
        }
        if (v[nr][nc] == 1) {
            v[nr][nc] = 0;
            bfs(nr, nc);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;

    for (int w = 0; w < t; w++) {
        cnt = 0;
        v.clear();
        cin >> m >> n >> k;
        for (int i = 0; i < n; i++) {
            vector<int> row;
            for (int j = 0; j < m; j++) {
                row.push_back(0);
            }
            v.push_back(row);
        }

        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            v[b][a] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    cnt += 1;
                    v[i][j] = 0;
                    bfs(i, j);
                }
            }
        }

        cout << cnt << "\n";
    }
}