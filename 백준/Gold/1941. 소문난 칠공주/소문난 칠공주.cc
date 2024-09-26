#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct node {
    int row;
    int col;
};

int ans = 0;
string v[5];
bool visited[25] = { false };

bool chk_near(int idx){ // idx는 시작 점
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0,1,0,-1 };

    int cnt = 1; // 7개가 있는지 확인
    bool chk[5][5] = { false }; // chk_near에서 사용하는 visited
    chk[idx/5][idx%5] = true;
    queue<node> q;
    q.push({ idx / 5, idx % 5 });

    while (!q.empty()) {
        node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];

            if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) { continue; }
            if (!visited[nr * 5 + nc]) { continue; }
            if (chk[nr][nc]) { continue; }

            chk[nr][nc] = true;
            cnt++;
            q.push({ nr, nc });
        }
    }

    if (cnt == 7) { return true; }
    else { return false; }
}

void dfs(int idx, int cnt, int s_cnt) {
    if (cnt == 7) {
        if (s_cnt >= 4) {
            if (chk_near(idx)) {ans++; }
        }
        return;
    }

    for (int i = idx; i < 25; i++) {
        if (visited[i]) { continue; }

        visited[i] = true;
        dfs(i, cnt + 1, s_cnt + (v[i / 5][i % 5] == 'S'));
        visited[i] = false;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    dfs(0, 0, 0);

    cout << ans;
}