#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
    int row;
    int col;
};

vector<vector<char>> v;
vector<vector<int>> dat;
queue<node> q;
int n, m;

void bfs() {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        node top = q.front();
        q.pop();

        if (v[top.row][top.col] == 'J') {
            if (top.row == 0 || top.col == 0 || top.row == n - 1 || top.col == m - 1) {
                cout << dat[top.row][top.col];
                exit(0);
            }
        }

        for (int i = 0; i < 4; i++) {
            int nr = top.row + dr[i];
            int nc = top.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (v[nr][nc] == '#' || v[nr][nc] == 'F') { // 벽 or 불 일때
                continue;
            }

            if (v[top.row][top.col] == 'J') {
                if (dat[nr][nc] <= dat[top.row][top.col] + 1) {
                    continue;
                }
                else {
                    v[nr][nc] = 'J';
                    dat[nr][nc] = dat[top.row][top.col] + 1;
                    q.push({ nr, nc });
                }
            }
            else if (v[top.row][top.col] == 'F') {
                v[nr][nc] = 'F';
                q.push({ nr, nc });
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<char> row;
        vector<int> row2;
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            row.push_back(tmp);
            row2.push_back(1e9);
            if (tmp == 'J') {
                q.push({ i, j });
            }
        }
        v.push_back(row);
        dat.push_back(row2);
    }

    node top = q.front();
    dat[top.row][top.col] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'F') {
                q.push({ i, j });
            }
        }
    }

    bfs();

    cout << "IMPOSSIBLE";
}