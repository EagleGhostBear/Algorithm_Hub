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
vector<vector<int>> dp; // dp[문자열 A의 자리수][문자열 B의 자리수] = 개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    dp.resize(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i - 1][j-1] + 1;
                //dp[j][i] = dp[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    /*
    for (int i = 0; i <= a.size(); i++) {
        for (int j = 0; j <= b.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << dp[a.size()][b.size()];
}