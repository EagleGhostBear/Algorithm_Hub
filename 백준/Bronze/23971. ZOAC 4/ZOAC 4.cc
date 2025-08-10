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

int h, w, n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> h >> w >> n >> m;
    ll col = w / (m + 1);
    if (w % (m + 1)) col += 1;
    ll row = h / (n + 1);
    if (h % (n + 1)) row += 1;
    cout << row * col;
}
/*

*/