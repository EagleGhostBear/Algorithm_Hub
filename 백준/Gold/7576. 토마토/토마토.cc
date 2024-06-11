#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
    int row;
    int col;
};

vector<vector<int>> v;
queue<node> q;
int n, m;

void bfs() {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        node top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = top.row + dr[i];
            int nc = top.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (v[nr][nc] == -1) {
                continue;
            }

            if (v[nr][nc] != 0 && v[nr][nc] <= v[top.row][top.col] + 1) {
                continue;
            }
            v[nr][nc] = v[top.row][top.col] + 1;
            q.push({ nr, nc });
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            row.push_back(tmp);
        }
        v.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                q.push({ i, j });
            }
        }
    }

    bfs();

    int maxv = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) {
                cout << -1;
                return 0;
            }
            else {
                if (v[i][j] > maxv) {
                    maxv = v[i][j];
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