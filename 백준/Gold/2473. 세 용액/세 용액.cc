#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
ll ans[4] = { 4000000000, 0, 0, 0 };
vector<ll> v;

void solution(int idx, int num1, int num2) {
    ll target = num1 + num2;
    int left = idx;
    int right = n - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        ll now = v[mid] + target;
        if (abs(now) < ans[0]) {
            ans[0] = abs(now);
            ans[1] = num1;
            ans[2] = num2;
            ans[3] = v[mid];
        }
        if (now == 0) {
            return;
        }
        else if (now < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (j + 1 < n) {
            solution(j + 1, v[i], v[j]);
        }
    }
    cout << ans[1] << " " << ans[2] << " " << ans[3];
}