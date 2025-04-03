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

ll n, p, q;
unordered_map<ll, ll> um;

ll solution(ll num) {
    if (um.find(num) != um.end()) return um[num];
    ll ret = solution(num / p) + solution(num / q);
    um[num] = ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> p >> q;
    um[0] = 1;
    cout << solution(n);
}