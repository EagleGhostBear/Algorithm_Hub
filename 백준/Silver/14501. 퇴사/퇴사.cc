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

int n;
vector<vector<int>> v;
vector<int> dp; // dp[날짜] = 비용

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>(2));
    dp.resize(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = 0; i <= n; i++) {
        int maxv = 0;
        for (int j = 0; j < i; j++) { // 이전 날짜들중에서 가장 비용이 높은걸 찾음
            if (j + v[j][0] - 1 < i) {
                maxv = max(maxv, dp[j]);
            }
        }
        dp[i] = maxv;
        if (i != n && i + v[i][0] - 1 < n) { // 현재 날짜의 상담을 수행할 수 있다면 비용에 추가
            dp[i] += v[i][1];
        }
    }

    cout << dp[n];
}