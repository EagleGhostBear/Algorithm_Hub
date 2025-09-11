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

int n, q;
vector<vector<int>> v;

void func1(int idx) {
    vector<int> tmp;
    tmp.push_back(v[idx].back());
    tmp.insert(tmp.end(), v[idx].begin(), v[idx].end() - 1);
    v[idx] = tmp;
    return;
}

void func2() {
    vector<vector<int>> tmp(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        tmp[j][n - 1 - i] = v[i][j];
    }
    v = tmp;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> v[i][j];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            int b;
            cin >> b;
            func1(b - 1);
        }
        else if (a == 2) func2();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
/*

*/