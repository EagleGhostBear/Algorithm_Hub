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

struct node {
    int idx, start, end, y;
};

struct compare {
    bool operator()(node left, node right) {
        if (left.end < right.end) return true;
        if (left.end > right.end) return false;

        if (left.start < right.start) return true;
        if (left.start > right.start) return false;

        return false;
    }
};

int n, q;
vector<int> v;
vector<node> tree;

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

    cin >> n >> q;
    for (int i = 0; i <= n; i++) v.push_back(i);
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree.push_back({ i, a, b, c });
    }
    sort(tree.begin(), tree.end(), compare());
    node prev = { 0,0,0,0 };
    for (int i = 0; i < tree.size(); i++) {
        if (prev.idx) {
            if (prev.start <= tree[i].start && tree[i].start <= prev.end && prev.y != tree[i].y) {
                unite(prev.idx, tree[i].idx);
            }
        }
        prev = tree[i];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) cout << "1\n";
        else cout << "0\n";
    }
}
/*

*/