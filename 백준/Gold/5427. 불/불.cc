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
int t, n, m;
bool chk = true;

void bfs() {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        node top = q.front();
        q.pop();

        if (v[top.row][top.col] == '@') {
            if (top.row == 0 || top.col == 0 || top.row == n - 1 || top.col == m - 1) {
                cout << dat[top.row][top.col] << "\n";
                chk = false;
                return;
            }
        }

        for (int i = 0; i < 4; i++) {
            int nr = top.row + dr[i];
            int nc = top.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (v[nr][nc] == '#' || v[nr][nc] == '*') { // 벽 or 불 일때
                continue;
            }

            if (v[top.row][top.col] == '@') {
                if (dat[nr][nc] <= dat[top.row][top.col] + 1) {
                    continue;
                }
                else {
                    v[nr][nc] = '@';
                    dat[nr][nc] = dat[top.row][top.col] + 1;
                    q.push({ nr, nc });
                }
            }
            else if (v[top.row][top.col] == '*') {
                v[nr][nc] = '*';
                q.push({ nr, nc });
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> m >> n;
        chk = true;
        v.clear();
        dat.clear();
        while (!q.empty()) { q.pop(); }
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            vector<char> row;
            vector<int> row2;
            for (int j = 0; j < m; j++) {
                row.push_back(tmp[j]);
                if (tmp[j] == '@') {
                    q.push({ i,j });
                    row2.push_back(1);
                }
                else {
                    row2.push_back(1e9);
                }
            }
            v.push_back(row);
            dat.push_back(row2);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == '*') {
                    q.push({ i,j });
                }
            }
        }

        bfs();

        if (chk) {
            cout << "IMPOSSIBLE" << "\n";
        }
    }
}