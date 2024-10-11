#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int n;
vector<int> ans(2);
vector<vector<int>> v;
vector<bool> slab1(19), slab2(19);

void dfs(int idx, int cnt, int color) {
    for (int i = idx + 1; i < n * n; i++) {
        int row = i / n;
        int col = i % n;
        if ((row + col) % 2 != color) { continue; } // 못놓는 색상 생략
        if (!v[row][col]) { continue; } // 비숍을 못 놓는 위치는 생략
        if (slab1[row + col] || slab2[row - col + (n - 1)]) { continue; } // 대각선이 중복되는 위치 생략

        v[row][col] = 0;
        slab1[row + col] = true;
        slab2[row - col + (n - 1)] = true;
        dfs(i, cnt + 1, color);
        v[row][col] = 1;
        slab1[row + col] = false;
        slab2[row - col + (n - 1)] = false;
    }

    ans[color] = max(ans[color], cnt);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    dfs(-1, 0, 0); // 흑 탐색
    dfs(-1, 0, 1); // 백 탐색

    cout << ans[0] + ans[1];
}