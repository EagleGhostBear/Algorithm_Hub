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

int n, m;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    dp.resize(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            total += tmp;
            dp[i][j] = total;
            if (i > 0) dp[i][j] += dp[i - 1][j];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        int minus1 = 0, minus2 = 0, plus1 = 0;
        if (y1 > 0) minus1 = dp[x2][y1 - 1];
        if (x1 > 0) minus2 = dp[x1 - 1][y2];
        if (x1 > 0 && y1 > 0) plus1 = dp[x1 - 1][y1 - 1];

        cout << dp[x2][y2] - minus1 - minus2 + plus1 << "\n";
    }
}
/*
(0,0) -> (x2, y2) 사각형의 넓이에서
(0,0) -> (x2, y1 - 1) 사각형, (0,0) -> (x1 - 1, y2) 사각형 2개의 사각형 넓이를 빼고
두번 빼진 (0,0) -> (x1 - 1, y1 - 1) 사각형 넓이를 한번 더 해준다.
*/