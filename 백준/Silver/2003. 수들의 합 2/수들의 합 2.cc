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

    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i) v[i] += v[i - 1];
    }
    int left = 0, right = 0;
    while (left < n && right < n) {
        int tot = v[right] - (left ? v[left - 1] : 0);
        if (tot < m) right++;
        else {
            if (tot == m) ans++;
            if (left == right) right++;
            else left++;
        }
    }
    cout << ans;
}