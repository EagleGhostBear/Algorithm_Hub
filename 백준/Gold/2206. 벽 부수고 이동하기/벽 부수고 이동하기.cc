#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct node {
    int row;
    int col;
    bool chk;
};

int n, m;

vector<vector<int>> v;
vector<vector<int>> dat1; // 사용X
vector<vector<int>> dat2; // 사용
queue<node> q;

void bfs() {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
                continue;
            }
            if (now.chk) { // 이미 벽을 뚫은 경우
                if (v[nr][nc] == 1) { // 벽을 향해
                    continue;
                }
                else { // 일반
                    if (dat2[nr][nc] <= dat2[now.row][now.col] + 1) {
                        continue;
                    }
                    else {
                        dat2[nr][nc] = dat2[now.row][now.col] + 1;
                        q.push({ nr, nc, true });
                    }
                }
            }
            else { // 벽을 안 뚫음
                if (v[nr][nc] == 1) {
                    if (dat2[nr][nc] <= dat1[now.row][now.col] + 1) {
                        continue;
                    }
                    else {
                        dat2[nr][nc] = dat1[now.row][now.col] + 1;
                        q.push({ nr, nc, true });
                    }
                }
                else {
                    if (dat1[nr][nc] <= dat1[now.row][now.col] + 1) {
                        continue;
                    }
                    else {
                        dat1[nr][nc] = dat1[now.row][now.col] + 1;
                        q.push({ nr, nc, false });
                    }
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> row1;
        vector<int> row2;
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            if (tmp[j] == '0') {
                row1.push_back(0);
            }
            else {
                row1.push_back(1);
            }
            row2.push_back(1e9);
        }
        v.push_back(row1);
        dat1.push_back(row2);
        dat2.push_back(row2);
    }

    dat1[0][0] = 1;
    q.push({ 0,0, false });
    bfs();

    if (dat1[n - 1][m - 1] == 1e9 && dat2[n - 1][m - 1] == 1e9) {
        cout << "-1";
    }
    else if (dat2[n - 1][m - 1] != 1e9) {
        cout << dat2[n - 1][m - 1];
    }
    else {
        cout << dat1[n - 1][m - 1];
    }
}