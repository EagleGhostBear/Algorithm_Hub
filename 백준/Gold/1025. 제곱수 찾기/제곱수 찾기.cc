#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, ans = -1;
vector<vector<int>> v;

void solution(int row, int col, int a, int b) {
    int num = v[row][col];
    while (-1 < row + a && row + a < n && -1 < col + b && col + b < m) {
        row += a;
        col += b;
        num *= 10;
        num += v[row][col];
        if (sqrt(num) == int(sqrt(num))) { // 끝까지 탐색 안해도됌으로 전진할때 마다 확인해준다.
            ans = max(ans, num);
        }
    }

}

void select_point(int row, int col) {
    // (8,8)이 최대
    for (int i = -n + 1; i <= n - 1; i++) {
        for (int j = -m + 1; j <= m - 1; j++) {
            if (!i && !j) { continue; }
            solution(row, col, i, j);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            v[i][j] = int(s[j] - '0');
            if (sqrt(v[i][j]) == int(sqrt(v[i][j]))) {
                ans = max(ans, v[i][j]);
            }
        }
    }

    // 시작점 선정 -> 나아갈 row, col 값을 선정 (-8 ~ 8)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            select_point(i, j);
        }
    }

    cout << ans;
}
/*
브루트포스로 해도 가능성이 작다

끝까지 탐색하는 것이 아닌 중간에 멈출수도 있습니다
1 3
162
answer : 16
*/