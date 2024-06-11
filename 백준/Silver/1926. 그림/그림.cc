#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> v;

int n, m;
int maxv = 0;
int nowv = 0;
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
        if (v[nr][nc] == 0) {
            continue;
        }

        v[nr][nc] = 0;
        nowv += 1;
        bfs(nr, nc);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

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
            if (v[i][j] != 0) {
                cnt += 1;
                nowv = 1;
                v[i][j] = 0;
                bfs(i, j);
                if (maxv < nowv) {
                    maxv = nowv;
                }
            }
        }
    }

    cout << cnt << "\n" << maxv;
}