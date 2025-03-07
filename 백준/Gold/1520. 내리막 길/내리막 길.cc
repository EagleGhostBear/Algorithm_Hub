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
    int h;
};

struct compare {
    bool operator()(node left, node right) {
        if (left.h < right.h) return true;
        if (left.h > right.h) return false;

        return false;
    }
};

int n, m;
vector<vector<int>> v;
vector<vector<int>> visited;
vector<vector<int>> dp; // dp[row][col] = 경우의 수

void dfs(int row, int col) {
    priority_queue<node, vector<node>, compare> pq; // 높이가 높은 순으로 출력
    pq.push({ row, col, v[row][col] });
    visited[0][0] = 1;

    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };
    while (pq.size()) {
        node now = pq.top();
        pq.pop();

        if (now.row == m - 1 && now.col == n - 1) continue;

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            if (v[now.row][now.col] <= v[nr][nc]) continue;

            dp[nr][nc] += dp[now.row][now.col];
            if (!visited[nr][nc]) {
                visited[nr][nc] = 1;
                pq.push({ nr, nc, v[nr][nc] });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    v.resize(m, vector<int>(n, 0));
    visited.resize(m, vector<int>(n, 0));
    dp.resize(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    
    dfs(0, 0);

    cout << dp[m - 1][n - 1];
}
/*
높이가 낮은 방향으로만 이동, 목적지까지 도달 가능한 루트의 개수
방법) 높이가 높은순으로 정렬해서 뽑으면 중복 탐색이 없을것이라 생각
*/