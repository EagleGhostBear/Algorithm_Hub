#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    int ans = 0, minVal = 1e4 + 1;
    for (int i = m; i <= n; i++) {
        double num = sqrt(i);
        if (int(num) == num) {
            ans += i;
            minVal = min(minVal, i);
        }
    }
    if (ans) cout << ans << "\n" << minVal;
    else cout << "-1";
}