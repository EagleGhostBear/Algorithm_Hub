#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m, ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    if (n > m) {
        int tmp = n;
        n = m;
        m = tmp;
    }
    ans += (n - 1);
    ans += n * (m - 1);
    cout << ans;
}