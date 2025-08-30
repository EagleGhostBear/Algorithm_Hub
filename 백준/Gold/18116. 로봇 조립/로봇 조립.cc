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

int n, m;
vector<int> v, cnt;

int find(int idx) {
    if (v[idx] == idx) return idx;
    return v[idx] = find(v[idx]);
}

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b) {
        v[root_a] = root_b;
        cnt[root_b] += cnt[root_a];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i <= 1e6; i++) v.push_back(i), cnt.push_back(1);
    for (int i = 0; i < n; i++) {
        char a;
        int b, c;
        cin >> a;
        if (a == 'I') {
            cin >> b >> c;
            unite(b, c);
        }
        if (a == 'Q') {
            cin >> b;
            cout << cnt[find(b)] << "\n";
        }
    }
}
/*

*/