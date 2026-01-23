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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    int left = 0, right = -1;
    vector<int> cnt(100001, 0);
    while (left < n && ++right < n) {
        cnt[v[right]]++;
        while (cnt[v[right]] > 1) cnt[v[left++]]--;
        ans += (right - left + 1);
    }
    cout << ans;
}