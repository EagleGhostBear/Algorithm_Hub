#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct node {
    int row;
    int col;
};

int n;
int maxv = 1;
int cnt;

vector<vector<int>> v;
vector<vector<int>> cv;
queue<node> q;
set<int> s;

void bfs() {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                continue;
            }
            if (cv[nr][nc] == -1) {
                continue;
            }
            cv[nr][nc] = -1;
            q.push({ nr, nc });
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            s.insert(tmp);
            row.push_back(tmp);
        }
        v.push_back(row);
    }

    for (auto it = s.begin(); it != s.end(); it++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][j] <= *it) {
                    v[i][j] = -1;
                }
            }
        }
        
        cnt = 0;
        cv.clear();
        cv.assign(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cv[i][j] != -1) {
                    cv[i][j] = -1;
                    cnt += 1;
                    q.push({ i, j });
                    bfs();
                }
            }
        }

        if (cnt > maxv) {
            maxv = cnt;
        }
    }

    cout << maxv;
}