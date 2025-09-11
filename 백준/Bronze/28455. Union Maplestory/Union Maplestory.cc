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

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int level = 0, stat = 0, sz = min(n, 42);
    for (int i = 0; i < sz; i++) {
        if (v[i] >= 250) stat += 5;
        else if (v[i] >= 200) stat += 4;
        else if (v[i] >= 140) stat += 3;
        else if (v[i] >= 100) stat += 2;
        else if (v[i] >= 60) stat += 1;
        level += v[i];
    }
    cout << level << " " << stat;
}
/*

*/