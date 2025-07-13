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

int n, m;
vector<int> pk, eh;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    pk.resize(m);
    eh.resize(m);
    for(int i=0; i<m; i++) cin >> pk[i] >> eh[i];
    sort(pk.begin(), pk.end());
    sort(eh.begin(), eh.end());

    int ans = 0;
    for (int i = 0; i < (n / 6); i++) {
        if (pk[0] < eh[0] * 6) ans += pk[0];
        else ans += (eh[0] * 6);
    }
    n %= 6;
    if (pk[0] < eh[0] * n) ans += pk[0];
    else ans += (eh[0] * n);

    cout << ans;
}