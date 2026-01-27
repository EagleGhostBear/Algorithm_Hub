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

    int n, k;
    cin >> n >> k;
    vector<int> v(n), cnt(200001, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    int left = 0, ans = 0;
    for (int right = 0; right < n; right++) {
        if (++cnt[v[right]] > k) while (cnt[v[right]] > k) --cnt[v[left++]];
        ans = max(ans, right - left + 1);
    }
    cout << ans;
}