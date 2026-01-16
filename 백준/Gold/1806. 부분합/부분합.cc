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

    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(i) v[i] += v[i - 1];
    }
    int left = 0, right = 0, ans = 1e5;
    while (left < n && right < n) {
        int tot = v[right] - (left ? v[left - 1] : 0);
        if (tot >= s) {
            ans = min(ans, right - left + 1);
            if (left < right) left++;
            else right++;
        }
        else right++;
    }
    if (ans == 1e5) cout << "0";
    else cout << ans;
}