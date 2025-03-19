#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int ans = 0, cnt = 1;
    while (n) {
        if (cnt > n) cnt = 1;
        n -= cnt++;
        ans++;
    }
    cout << ans;
}