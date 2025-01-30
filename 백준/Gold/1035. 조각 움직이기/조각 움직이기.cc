#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

using Board = array<bitset<5>, 5>;
bitset<1 << 25> visited;
int total_cnt = 0;

struct Converter {
    Board operator()(int n) {
        Board ret;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (n & (1 << i * 5 + j)) { ret[i][j] = 1; }
            }
        }
        return ret;
    }
    int operator()(Board board) {
        int ret = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (board[i][j]) { ret |= (1 << i * 5 + j); }
            }
        }
        return ret;
    }
} Conv; // 전연객체 // Conv(state)처럼 객체 생성 없이 사용할 수 있음.

bool IsConnected(Board board) { // 조각(*) 1개를 기점으로 모든 조각(*)들이 연결되었는지 확인
    int chk_cnt = total_cnt - 1;

    queue<pair<int, int>> q;
    bool break_point = false;
    for (int i = 0; i < 5; i++) {
        if (break_point) { break; }
        for (int j = 0; j < 5; j++) {
            if (board[i][j]) {
                q.push({ i, j });
                break_point = true;
                break;
            }
        }
    }

    array<bitset<5>, 5> visited_chk;
    visited_chk[q.front().first][q.front().second] = 1;

    while (!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        int dr[] = { -1, 0, 1, 0 };
        int dc[] = { 0,1,0,-1 };
        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) { continue; }
            if (!board[nr][nc]) { continue; }
            if (visited_chk[nr][nc]) { continue; }
            visited_chk[nr][nc] = 1;
            chk_cnt--;
            q.push({ nr, nc });
        }
    }

    if (chk_cnt) { // 연결 안됨
        return false;
    }
    else { // 연결 됨
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Board init_board;
    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == '*') { init_board[i][j] = 1; total_cnt++; }
        }
    }
    visited[Conv(init_board)];
    queue<pair<int, int>> q;
    q.push({ Conv(init_board), 0 });

    while (!q.empty()) { // BFS로 조각(*)들을 옮겨보면서 전부다 연결된 상황을 찾음
        Board now_board = Conv(q.front().first);
        int now_cnt = q.front().second;
        q.pop();

        if (IsConnected(now_board)) { // BFS 특성상 가장 빠르게 연결 조건을 완성한 상태가 최소 움직임이다.
            cout << now_cnt << '\n';
            return 0;
        }

        int dr[] = { -1, 0, 1, 0 };
        int dc[] = { 0,1,0,-1 };

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!now_board[i][j]) { continue; } // 조각(*)이 아닌 부분은 넘긴다.
                for (int k = 0; k < 4; k++) { // 조각(*)을 상,하,좌,우로 이동시켜본다.
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) { continue; }
                    if (now_board[nr][nc]) { continue; } // 이미 조각(*)이 있는 방향은 스킵
                    now_board[i][j] = 0;
                    now_board[nr][nc] = 1;
                    int next_board = Conv(now_board);
                    if (!visited[next_board]) { // 방문한적이 있는 상태인지 확인
                        visited[next_board] = 1;
                        q.push({ next_board, now_cnt + 1 });
                    }
                    // 보드는 다른 방향으로 이동할때도 사용해야 하므로 원래 상태로 되돌린다.
                    now_board[i][j] = 1;
                    now_board[nr][nc] = 0;
                }
            }
        }
    }
}