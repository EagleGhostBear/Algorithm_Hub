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

ll n, m;
vector<ll> v(1000001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (ll i = 2; i <= m; i++) {
        if (!v[i]) {
            if(n <= i) cout << i << "\n";
            for (ll j = i; i * j <= m; j++) {
                v[i * j] = 1;
            }
        }
    }
}