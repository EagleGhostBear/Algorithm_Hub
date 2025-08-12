#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    ll cnt = 0, val = 1;
    for (ll i = 0; val <= 1e9; i++) {
        val += (6 * i);
        cnt++;
        if (n <= val) break;
    }
    cout << cnt;
}
/*
50-> 166,666,666.6

1개 -> 6개 -> 12개 -> 18개 -> 24개 -> 30개
1, 7, 19, 37, 61, 91
0, 1, 3, 6, 10, 15
*/