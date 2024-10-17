#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int idx;
    int val;
};

bool compare_val(node left, node right) {
    return left.val < right.val;
}

int m, n, ans = 0;
vector<vector<node>> v;

bool is_equal(int i, int j) {
    for (int k = 0; k < n; k++) {
        if (v[i][k].idx != v[j][k].idx) { return false; }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    v.resize(m, vector<node>(n));
    for (int i = 0; i < m; i++) { // 100 * log(10,000)
        for (int j = 0; j < n; j++) {
            cin >> v[i][j].val;
            if (j - 1 >= 0 && v[i][j].val == v[i][j - 1].val) {
                v[i][j].idx = v[i][j - 1].idx;
            }
            else {
                v[i][j].idx = j;
            }
        }
        sort(v[i].begin(), v[i].end(), compare_val);
    }

    for (int i = 0; i < m; i++) { // 100 * 100 * 10,000 = 100,000,000
        for (int j = i + 1; j < m; j++) {
            if (is_equal(i, j)) { ans++; }
        }
    }

    cout << ans;
}