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

struct node {
    int exp;
    int idx; // 해당 dp의 idx

    bool operator<(node right) const {
        if (exp < right.exp) { return false;; }
        if (exp > right.exp) { return true; }
        
        return false;
    }
};

int n;
vector<vector<int>> v;
vector<int> dp; // dp[날짜] = 총 금액
priority_queue<node> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n + 1, vector<int>(2));
    dp.resize(n+2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = 1; i <= n; i++) { // 1,500,000 * 50 = 75,000,000
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + v[i][0] - 1 <= n) { // 현재 날짜의 상담을 수행할 수 있을때
            dp[i + v[i][0]] = max(dp[i + v[i][0]], dp[i] + v[i][1]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
}