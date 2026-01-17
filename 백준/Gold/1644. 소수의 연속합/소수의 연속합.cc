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
    int ans = 0;
    vector<int> dec;
    vector<bool> tmp(n + 1, true);
    for (int i = 2; i <= n; i++) {
        if (!tmp[i]) continue;
        for (int j = 2; j <= n; j++) {
            if (i * j > n) break;
            tmp[i * j] = false;
        }
        dec.push_back(i);
        if (dec.size() > 1) dec.back() += dec[dec.size() - 2];
    }
    int left = 0, right = 0;
    while (left < dec.size() && right < dec.size()) {
        int tot = dec[right] - (left ? dec[left - 1] : 0);

        if (tot == n) {
            ans++;
            left++;
        }
        else if (tot > n) left++;
        else if (tot < n) right++;
    }
    cout << ans;
}