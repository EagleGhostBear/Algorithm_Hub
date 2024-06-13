#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
    int row;
    int col;
};

int t, l;
vector<vector<int>> v;
queue<node> q;

void bfs() {
    int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dc[] = {-2, -1, 1, 2, 2, 1, -1, -2};

    while (!q.empty()) {
        node top = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nr = top.row + dr[i];
            int nc = top.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= l || nc >= l) {
                continue;
            }
            if (v[nr][nc] <= v[top.row][top.col] + 1) {
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

    cin >> t;

    for (int k = 0; k < t; k++) {
        v.clear();
        cin >> l;
        for (int i = 0; i < l; i++) {
            vector<int> row;
            for (int j = 0; j < l; j++) {
                row.push_back(1e9);
            }
            v.push_back(row);
        }

        int a, b, c, d;
        cin >> a >> b;
        cin >> c >> d;

        v[a][b] = 0;
        q.push({ a, b });

        bfs();

        cout << v[c][d] << "\n";
    }
}