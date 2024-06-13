#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
    int h;
    int row;
    int col;
};

int n, m, h;
vector<vector<vector<int>>> v;
queue<node> q;

int maxv = 0;

void bfs() {
    int dh[] = {0, 0, 0, 0, -1, 1};
    int dr[] = {-1, 0, 1, 0, 0, 0};
    int dc[] = {0, 1, 0, -1, 0, 0};

    while (!q.empty()) {
        node top = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nh = top.h + dh[i];
            int nr = top.row + dr[i];
            int nc = top.col + dc[i];
            if (nh < 0 || nr < 0 || nc < 0 || nh >= h || nr >= n || nc >= m) {
                continue;
            }
            if (v[nh][nr][nc] == -1) {
                continue;
            }
            if (v[nh][nr][nc] <= v[top.h][top.row][top.col] + 1) {
                continue;
            }
            v[nh][nr][nc] = v[top.h][top.row][top.col] + 1;
            q.push({ nh, nr, nc });
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        vector<vector<int>> height;
        for (int j = 0; j < n; j++) {
            vector<int> row;
            for (int k = 0; k < m; k++) {
                int tmp;
                cin >> tmp;
                if (tmp == 1) {
                    q.push({ i, j, k });
                    row.push_back(tmp);
                }
                else if (tmp == -1) {
                    row.push_back(tmp);
                }
                else {
                    row.push_back(1e9);
                }
            }
            height.push_back(row);
        }
        v.push_back(height);
    }

    bfs();

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (v[i][j][k] == 1e9) {
                    cout << -1;
                    exit(0);
                }
                if (v[i][j][k] > maxv) {
                    maxv = v[i][j][k];
                }
            }
        }
    }

    if (maxv == 1) {
        cout << 0;
    }
    else {
        cout << maxv - 1;
    }
}