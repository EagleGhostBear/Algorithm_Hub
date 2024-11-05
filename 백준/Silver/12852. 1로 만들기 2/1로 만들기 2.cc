#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
vector<int> dp;
vector<vector<int>> path;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    dp.resize(n+1);
    path.resize(n + 1, vector<int>());
    dp[1] = 0;
    path[1].push_back(1);
    for (int i = 2; i <= n; i++) {

        dp[i] = dp[i - 1] + 1;
        path[i] = path[i - 1];
        if (i % 3 == 0 && dp[i] > dp[i/3] + 1) {
            path[i] = path[i/3];
            dp[i] = dp[i / 3] + 1;
        }
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            path[i] = path[i / 2];
            dp[i] = dp[i / 2] + 1;
        }
        path[i].push_back(i);
    }

    cout << dp[n] << "\n";
    for (int i = path[n].size() - 1; i > -1; i--) {
        cout << path[n][i] << " ";
    }
}