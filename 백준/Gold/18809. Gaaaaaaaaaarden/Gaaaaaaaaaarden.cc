#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

struct node {
    int row;
    int col;
    int val;
    int turn = 0;
};

int n, m, g, r, ans;
vector<vector<node>> v;
vector<vector<node>> board;
deque<node> dq_g;
deque<node> dq_r;

int bfs() {
    int cnt = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    deque<node> q_g = dq_g;
    deque<node> q_r = dq_r;

    while (!q_g.empty() && !q_r.empty()) {
        int g_size = q_g.size();
        int r_size = q_r.size();

        for (int j = 0; j < g_size; j++) {
            node now_g = q_g.front();
            q_g.pop_front();

            if (board[now_g.row][now_g.col].val == -1) { continue; } // 꽃이 된 자리는 생략

            for (int i = 0; i < 4; i++) { // 초록
                int nr = now_g.row + dr[i];
                int nc = now_g.col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) { continue; }

                if (board[nr][nc].val == -3 && board[now_g.row][now_g.col].turn + 1 == board[nr][nc].turn) { // 서로 색이 다른 배양액일 경우
                    board[nr][nc].val = -1;
                    cnt++;
                }
                else if (board[nr][nc].val != 2 && board[nr][nc].val != 1) { // 호수, 같은 배양액, 꽃 생략
                    continue;
                }
                else {
                    board[nr][nc].val = board[now_g.row][now_g.col].val;
                    board[nr][nc].turn = board[now_g.row][now_g.col].turn + 1;
                    q_g.push_back({ nr, nc });
                }
            }
        }

        for (int j = 0; j < r_size; j++) {
            node now_r = q_r.front();
            q_r.pop_front();

            if (board[now_r.row][now_r.col].val == -1) { continue; } // 꽃이 된 자리는 생략

            for (int i = 0; i < 4; i++) { // 빨강
                int nr = now_r.row + dr[i];
                int nc = now_r.col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m) { continue; }

                if (board[nr][nc].val == 3 && board[now_r.row][now_r.col].turn + 1 == board[nr][nc].turn) { // 서로 색이 다른 배양액일 경우
                    board[nr][nc].val = -1;
                    cnt++;
                }
                else if (board[nr][nc].val != 2 && board[nr][nc].val != 1) { // 호수, 같은 배양액, 꽃 생략
                    continue;
                }
                else {
                    board[nr][nc].val = board[now_r.row][now_r.col].val;
                    board[nr][nc].turn = board[now_r.row][now_r.col].turn + 1;
                    q_r.push_back({ nr, nc });
                }
            }
        }
    }
    return cnt;
}

void sel_r(int idx, int level) { // 빨간 배양액 = -3
    if (level == r) {
        board = v;
        ans = max(ans, bfs());
        return;
    }

    for (int i = idx + 1; i < n * m; i++) {
        if (v[i / m][i % m].val != 2) { continue; }

        v[i / m][i % m].val = -3;
        dq_r.push_back({ i / m, i % m});

        sel_r(i, level + 1);

        v[i / m][i % m].val = 2;
        dq_r.pop_back();
    }
}

void sel_g(int idx, int level) { // 초록 배양액 = 3
    if (level == g) {
        sel_r(-1, 0);
        return;
    }

    for (int i = idx + 1; i < n * m; i++) {
        if (v[i / m][i % m].val != 2) { continue; }

        v[i / m][i % m].val = 3;
        dq_g.push_back({ i / m, i % m});

        sel_g(i, level + 1);

        v[i / m][i % m].val = 2;
        dq_g.pop_back();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> g >> r;

    v.resize(n, vector<node>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j].val;
        }
    }

    sel_g(-1, 0);

    cout << ans;
}