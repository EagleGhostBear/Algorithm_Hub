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

int g, p;
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

    cin >> g >> p;
    v.resize(g + 1);
    for (int i = 0; i <= g; i++) v[i] = i;
    int ans = 0;
    for (int i = 0; i < p; i++) {
        int a;
        cin >> a;
        int root_a = find(a);
        if (root_a == 0) break;
        else {
            ans++;
            unite(root_a, root_a - 1);
        }
    }
    cout << ans;
}
/*

*/