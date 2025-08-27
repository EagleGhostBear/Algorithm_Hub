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

using namespace std;

typedef long long ll;

int t, n, k, m;
vector<int> v;

int find(int idx) {
    if (v[idx] == idx) return idx;
    return v[idx] = find(v[idx]);
}

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b) {
        v[root_a] = root_b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int l = 1; l <= t; l++) {
        cout << "Scenario " << l << ":\n";
        int a, b;
        cin >> n >> k;
        v.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) v[i] = i;
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            unite(a, b);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (find(a) == find(b)) cout << "1\n";
            else cout << "0\n";
        }
        cout << "\n";
    }
}
/*

*/