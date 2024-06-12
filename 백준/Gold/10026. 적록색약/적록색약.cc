#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n;
vector<vector<char>> v1;
vector<vector<char>> v2;
int cnt1 = 0;
int cnt2 = 0;

void bfs1(int row, int col, char color) {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
            continue;
        }
        if (v1[nr][nc] != color) {
            continue;
        }
        v1[nr][nc] = 'X';
        bfs1(nr, nc, color);
    }
}

void bfs2(int row, int col, char color) {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
            continue;
        }
        if (v2[nr][nc] != color) {
            continue;
        }
        v2[nr][nc] = 'X';
        bfs2(nr, nc, color);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<char> row1;
        vector<char> row2;
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            if (tmp[j] == 'G') {
                row1.push_back(tmp[j]);
                row2.push_back('R');
            }
            else {
                row1.push_back(tmp[j]);
                row2.push_back(tmp[j]);
            }
        }
        v1.push_back(row1);
        v2.push_back(row2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v1[i][j] != 'X') {
                cnt1 += 1;
                bfs1(i, j, v1[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v2[i][j] != 'X') {
                cnt2 += 1;
                bfs2(i, j, v2[i][j]);
            }
        }
    }

    cout << cnt1 << " " << cnt2;
}