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
vector<pair<int, int>> wall;

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

    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) v[i] = i;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        wall.push_back({ from, to });
    }
    sort(wall.begin(), wall.end());
    pair<int, int> prev;
    if (wall.size()) prev = wall[0];
    for (int i = 1; i < wall.size(); i++) {
        if (wall[i].first <= prev.second) prev.second = max(prev.second, wall[i].second);
        else {
            for (int j = prev.first; j < prev.second; j++) unite(j, j + 1);
            prev = wall[i];
        }
    }
    for (int j = prev.first; j < prev.second; j++) unite(j, j + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) if (v[i] == i) ans++;
    cout << ans;
}
/*

*/