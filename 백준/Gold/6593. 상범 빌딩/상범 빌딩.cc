#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct node {
    int l;
    int row;
    int col;
};

int l, r, c;

vector<vector<vector<int>>> v;
queue<node> q;
node target;

void bfs() {
    int dl[] = { 0, 0, 0, 0, 1, -1 };
    int dr[] = {-1, 0, 1, 0, 0, 0};
    int dc[] = {0, 1, 0, -1, 0, 0};

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            int nl = now.l + dl[i];
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nl < 0 || nr < 0 || nc < 0 || nl >= l || nr >= r || nc >= c) {
                continue;
            }
            if (v[nl][nr][nc] == -1) {
                continue;
            }
            if (v[nl][nr][nc] <= v[now.l][now.row][now.col] + 1) {
                continue;
            }
            v[nl][nr][nc] = v[now.l][now.row][now.col] + 1;
            q.push({ nl, nr, nc });
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) {
            break;
        }
        v.clear();

        for (int i = 0; i < l; i++) {
            vector<vector<int>> row1;
            for (int j = 0; j < r; j++) {
                vector<int> row2;
                string tmp;
                cin >> tmp;
                for (int k = 0; k < c; k++) {
                    if (tmp[k] == 'S') {
                        q.push({ i, j, k });
                        row2.push_back(0);
                    }
                    else if (tmp[k] == 'E') {
                        target.l = i;
                        target.row = j;
                        target.col = k;
                        row2.push_back(1e9);
                    }
                    else if (tmp[k] == '#') {
                        row2.push_back(-1);
                    }
                    else {
                        row2.push_back(1e9);
                    }
                }
                row1.push_back(row2);
            }
            v.push_back(row1);
        }

        bfs();

        if (v[target.l][target.row][target.col] == 1e9) {
            cout << "Trapped!" << "\n";
        }
        else {
            cout << "Escaped in " << v[target.l][target.row][target.col] << " minute(s)." << "\n";
        }
    }
}