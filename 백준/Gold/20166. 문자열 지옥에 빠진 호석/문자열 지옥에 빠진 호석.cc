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

int n, m, k;
vector<vector<char>> v;
unordered_map<string, int> um;

void solution(int row, int col, string s) {
    if (s.size() == 5) return;

    int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    for (int dir = 0; dir < 8; dir++) {
        int nr = row + dr[dir];
        int nc = col + dc[dir];
        if (nr < 0) nr = n - 1;
        else if (nr >= n) nr = 0;
        if (nc < 0) nc = m - 1;
        else if (nc >= m) nc = 0;
        um[s + v[nr][nc]]++;
        solution(nr, nc, s + v[nr][nc]);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    v.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> v[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s = ""; s += v[i][j];
            solution(i, j, s);
        }
    }

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        cout << um[s] << "\n";
    }
}