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

    int n, d, k, c, ans = 0, cnt = 1;
    cin >> n >> d >> k >> c;
    vector<int> v(n), sushi(3001, 0);
    sushi[c]++;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < k; i++) if (sushi[v[i]]++ == 0) cnt++;
    ans = cnt;
    for (int b = 0; b < n; b++) {
        int f = (b + k >= n ? b + k - n : b + k);
        if (--sushi[v[b]] == 0) cnt--;
        if (sushi[v[f]]++ == 0) cnt++;
        ans = max(ans, cnt);
    }
    cout << ans;
}