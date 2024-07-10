#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> dp;

int main(int argc, char** argv) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i <= n; i++) {
        dp.push_back(0);
    }
    int maxv = -1;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        maxv = max(maxv, dp[tmp] = dp[tmp - 1] + 1);
    }

    cout << n - maxv;
}