#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

ll n, disk, cnt = 0;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (ll i = 0; i < n; i++) cin >> v[i];
    cin >> disk;

    for (ll i = 0; i < n; i++) {
        cnt += (v[i] / disk);
        if (v[i] % disk) cnt += 1;
    }

    cout << disk * cnt;
}