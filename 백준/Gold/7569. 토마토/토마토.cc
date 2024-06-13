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

int maxv = 1;
int cnt = 0;

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
            if (v[nh][nr][nc] == 1e9) {
                cnt -= 1;
            }
            v[nh][nr][nc] = v[top.h][top.row][top.col] + 1;
            if (v[nh][nr][nc] > maxv) {
                maxv = v[nh][nr][nc];
            }
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
                    cnt += 1;
                    row.push_back(1e9);
                }
            }
            height.push_back(row);
        }
        v.push_back(height);
    }

    if (cnt == 0) {
        cout << 0;
        exit(0);
    }

    bfs();

    if (cnt == 0) {
        cout << maxv - 1;
    }
    else {
        cout << -1;
    }
}