#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int ans = 26;
vector<vector<int>> v;
vector<int> paper = { 5, 5, 5, 5, 5 };

bool is_fin() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) if (v[i][j] != 0) return false;
    return true;
}

bool is_chk(int row, int col, int sz) {
    if (row + sz - 1 > 9 || col + sz - 1 > 9) return false;
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) if (!v[i + row][j + col]) return false;
    return true;
}

void update(int row, int col, int sz, int val) {
    for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) v[i + row][j + col] = val;
    return;
}

void dfs(int row, int col, int cnt) {
    if (ans <= cnt) return;
    while (!v[row][col]) {
        col++;
        if (col == 10) row++, col = 0;
        if (row == 10) {
            if (is_fin()) ans = min(ans, cnt);
            return;
        }
    }

    for (int sz = 5; sz > 0; sz--) {
        if (paper[sz - 1] && is_chk(row, col, sz)) {
            paper[sz - 1]--;
            update(row, col, sz, 0);
            dfs(row, col, cnt + 1);
            paper[sz - 1]++;
            update(row, col, sz, 1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    v.resize(10, vector<int>(10));
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> v[i][j];

    dfs(0, 0, 0);

    if (ans == 26) cout << "-1";
    else cout << ans;
}