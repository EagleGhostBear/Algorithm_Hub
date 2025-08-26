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
vector<int> v;

int find(int idx) {
    if (v[idx] == idx) {
        return idx;
    }
    return v[idx] = find(v[idx]);
}

void unite(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if (roota != rootb) {
        v[rootb] = roota;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) v.push_back(i);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a) {
            if (find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
        else unite(b, c);
    }
}
/*

*/