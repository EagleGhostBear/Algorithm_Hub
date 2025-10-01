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

int n, m, ans = 1;
vector<vector<int>> v;

bool solution(int row, int col, int sz, int val) {
    if ((v[row][col + sz] == val) && (v[row + sz][col] == val) && (v[row + sz][col + sz] == val)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) v[i][j] = s[j] - '0';
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        for (int k = min(n - 1 - i, m - 1 - j); k > 0; k--) {
            if (solution(i, j, k, v[i][j])) {
                ans = max(ans, (k + 1) * (k + 1));
                break;
            }
        }
    }
    cout << ans;
}