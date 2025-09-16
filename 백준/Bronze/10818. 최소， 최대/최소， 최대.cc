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
#include <iomanip>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int minv = 1e7, maxv = -1e7;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        minv = min(minv, a);
        maxv = max(maxv, a);
    }
    cout << minv << " " << maxv;
}
/*

*/