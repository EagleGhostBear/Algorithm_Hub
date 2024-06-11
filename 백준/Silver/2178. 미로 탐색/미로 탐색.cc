#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> dat;

int n, m;

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
        if (dat[nr][nc] <= dat[row][col] + 1) {
            continue;
        }

        dat[nr][nc] = dat[row][col] + 1;
        bfs(nr, nc);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {
            row.push_back(int(tmp[j]) - 48);
        }
        v.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            row.push_back(1e9);
        }
        dat.push_back(row);
    }

    dat[0][0] = 1;
    bfs(0, 0);

    cout << dat[n - 1][m - 1];
}