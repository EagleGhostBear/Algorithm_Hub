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
    for (int i = 0; i <= n; i++) v[i] = i;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int a;
        cin >> a;
        if(a) unite(i + 1, j + 1);
    }

    int num = 0;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        
        if (i == 0) num = find(a);
        else if (i && num != find(a)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
/*

*/