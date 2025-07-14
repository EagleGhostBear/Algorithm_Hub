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

int n, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l;
    bool chk = true;
    for (int len = l; len <= 100; len++) {
        ll total = 0;
        for (int i = 0; i < len; i++) total += i;
        if (n < total) continue;
        if ((n - total) % len == 0) {
            int p = (n - total) / len;
            for (int i = p; i < p + len; i++) cout << i << " ";
            chk = false;
            break;
        }
    }
    if (chk) cout << "-1";
}