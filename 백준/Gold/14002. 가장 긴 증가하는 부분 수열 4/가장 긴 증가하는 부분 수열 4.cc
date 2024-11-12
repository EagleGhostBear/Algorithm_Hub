#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<vector<int>> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    dp.resize(n, vector<int>());

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i-1; j > -1; j--) {
            if (v[j] < v[i] && dp[i].size() < dp[j].size()) {
                dp[i].clear();
                dp[i] = dp[j];
            }
        }
        dp[i].push_back(v[i]);
        if (ans.size() < dp[i].size()) {
            ans.clear();
            ans = dp[i];
        }
    }

    cout << ans.size() << "\n";
    for (auto s : ans) {
        cout << s << " ";
    }
}