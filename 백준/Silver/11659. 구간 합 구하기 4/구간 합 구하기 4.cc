#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
vector<int> v;
vector<ll> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    dp[0] = v[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + v[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << dp[b - 1] << "\n";
        }
        else {
            cout << dp[b - 1] - dp[a - 2] << "\n";
        }
    }
}