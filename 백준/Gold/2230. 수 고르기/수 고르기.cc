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

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int left = 0, right = 0, ans = 2e9;
    while (left < v.size() && right < v.size()) {
        int gap = abs(v[right] - v[left]);
        if (gap >= m) ans = min(ans, gap);

        if (left == right) right++;
        else if (gap < m) right++;
        else left++;
    }
    cout << ans;
}