#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct node {
    int row;
    int col;
    int dis;
    int turn;
};

int n, m, p;
int v[1000][1000];
int mv[10]; // 유저별 몇칸 움직이는지
int ans[10];
vector<queue<node>> q(10); // 플레이어별 node

bool is_chk() {
    for (int i = 0; i < q.size(); i++) if (q[i].size()) return true;
    return false;
}

void bfs() {
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while (is_chk()) {
        for (int i = 0; i < q.size(); i++) {
            int loop_turn = -1;
            if (q[i].size()) loop_turn = q[i].front().turn;
            while (q[i].size() && loop_turn == q[i].front().turn) {
                node now = q[i].front();
                q[i].pop();

                if (!now.dis) {
                    q[i].push({ now.row, now.col, mv[v[now.row][now.col]], now.turn + 1});
                    continue;
                }

                for (int j = 0; j < 4; j++) {
                    int nr = now.row + dr[j];
                    int nc = now.col + dc[j];
                    if (nr < 0 || nc < 0 || nr >= n || nc >= m || v[nr][nc]) continue;

                    v[nr][nc] = v[now.row][now.col];
                    ans[v[now.row][now.col]]++;
                    q[i].push({ nr, nc, now.dis - 1, now.turn });
                }
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    for (int i = 1; i <= p; i++) cin >> mv[i];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') v[i][j] = 10;
            else if (s[j] == '.') v[i][j] = 0;
            else {
                int num = s[j] - '0';
                q[num].push({ i, j, mv[num], 0 });
                v[i][j] = num;
                ans[num]++;
            }
        }
    }

    bfs();

    for (int i = 1; i <= p; i++) cout << ans[i] << " ";
}