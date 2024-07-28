#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int total = 0;
vector<int> visited_row;
vector<int> visited_col;
vector<int> visited_slab1; // 양의 기울기
vector<int> visited_slab2; // 음의 기울기

void dfs(int row, int level) {
    if (level == n) {
        total += 1;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (visited_row[row] != 0) { continue; }
        if (visited_col[col] != 0) { continue; }
        if (visited_slab1[row + col] != 0) { continue; }
        if (visited_slab2[row - col + (n - 1)] != 0) { continue; }

        visited_row[row] = 1;
        visited_col[col] = 1;
        visited_slab1[row + col] = 1;
        visited_slab2[row - col + (n - 1)] = 1;

        dfs(row + 1, level + 1);

        visited_row[row] = 0;
        visited_col[col] = 0;
        visited_slab1[row + col] = 0;
        visited_slab2[row - col + (n - 1)] = 0;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    visited_row.resize(n, 0);
    visited_col.resize(n, 0);
    visited_slab1.resize(2 * n - 1, 0);
    visited_slab2.resize(2 * n - 1, 0);

    dfs(0, 0);

    cout << total;
}