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
priority_queue<int, vector<int>, greater<int>> pq;
int n;

void bfs() {
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    int cnt = 1;

    while (!q.empty()) {
        node top = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = top.row + dr[i];
            int nc = top.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) {
                continue;
            }
            if (v[nr][nc] != 1) {
                continue;
            }
            v[nr][nc] = 0;
            q.push({ nr, nc });
            cnt += 1;
        }
    }

    pq.push(cnt);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<int> row;
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            row.push_back(int(tmp[j]) - 48);
        }
        v.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 1) {
                v[i][j] = 0;
                q.push({ i, j });
                bfs();
            }
        }
    }

    cout << pq.size() << "\n";
    int size = pq.size();
    for (int i = 0; i < size; i++) {
        cout << pq.top() << "\n";
        pq.pop();
    }
}