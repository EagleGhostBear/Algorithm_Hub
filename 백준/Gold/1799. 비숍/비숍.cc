#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans(2);
vector<vector<pair<int, int>>> v(2);
vector<bool> slab1(19), slab2(19);

void dfs(int idx, int cnt, int color) {
    for (int i = idx + 1; i < v[color].size(); i++) {
        int row = v[color][i].first;
        int col = v[color][i].second;
        if (slab1[row + col] || slab2[row - col + (n - 1)]) { continue; } // 대각선이 중복되는 위치 생략

        slab1[row + col] = true;
        slab2[row - col + (n - 1)] = true;
        dfs(i, cnt + 1, color);
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
    v.resize(2, vector<pair<int, int>>(2 * n - 1));

    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp) { v[(i + j) % 2].push_back({ i, j }); } // 흑, 백 칸에 둘 수 있는만 따로 저장
        }
    }

    dfs(-1, 0, 0); // 흑 탐색
    dfs(-1, 0, 1); // 백 탐색

    cout << ans[0] + ans[1];
}