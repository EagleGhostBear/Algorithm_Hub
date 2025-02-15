#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, ori;
vector<int> dp; // dp[자리][0, 1] = 경우의 수
// dp[][0] = 0
// dp[][1] = 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> ori;
    n = abs(ori);
    dp.resize(n + 1);
    dp[0] = 0;
    if(n) dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
    }

    if(!n) cout << "0\n";
    else if (ori < 0 && !(n % 2)) cout << "-1\n";
    else cout << "1\n";
    cout << dp[n];
}