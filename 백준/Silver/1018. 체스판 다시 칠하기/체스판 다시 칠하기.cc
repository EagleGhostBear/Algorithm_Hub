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

int n, m, ans = 1e9;
vector<vector<int>> v;

int solution(int row, int col) {
    int ans1 = 0, ans2 = 0;
    for (int i = row; i < row + 8; i++) {
        for (int j = col; j < col + 8; j++) {
            if ((i + j) % 2) {
                if (v[i][j] == 'W') ans1++;
                else ans2++;
            }
            else {
                if (v[i][j] == 'B') ans1++;
                else ans2++;
            }
        }
    }
    return min(ans1, ans2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) v[i][j] = s[j];
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (i + 8 > n || j + 8 > m) continue;
        ans = min(ans, solution(i, j));
    }

    cout << ans;
}