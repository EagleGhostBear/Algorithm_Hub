#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct node {
    int row, col, val;
};

struct compare {
    bool operator()(node left, node right) const {
        if (left.val > right.val) return true;
        if (left.val < right.val) return false;
        return false;
    }
};

int n, ans = 1;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
vector<vector<int>> v;
vector<vector<vector<int>>> dp; // dp[row][col][상,우,하,좌,현재위치] = 넘어온 최대값
priority_queue<node, vector<node>, compare> pq;

int reverse_dir(int dir) {
    return dir = (dir + 2) % 4;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    dp.resize(n, vector<vector<int>>(n, vector<int>(5, 0)));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j][4] = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> v[i][j];
        pq.push({ i, j, v[i][j] });
    }

    while (pq.size()) {
        node now = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
            if (v[now.row][now.col] >= v[nr][nc]) continue;

            int r = reverse_dir(i);
            dp[nr][nc][r] = dp[now.row][now.col][4] + 1;
            dp[nr][nc][4] = max(dp[nr][nc][4], dp[nr][nc][r]);
            ans = max(ans, dp[nr][nc][4]);
        }
    }
    cout << ans;
}
/*
작은애가 본인기준으로 큰애들 값을 갱신해주는게 맞다.
pq로 가장 작은애들부터 계산해나간다? -> 그러면 재계산이 없을거임
*/