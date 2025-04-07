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

int n, x;
vector<int> v, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> x;

    ans.resize(x + 1, 0);
    for (int i = 0; i < n; i++) {
        int now = v[i];
        if (now >= x) continue;
        if (ans[now]) ans[0] += ans[now];
        else ans[x - now]++;
    }
    cout << ans[0];
}