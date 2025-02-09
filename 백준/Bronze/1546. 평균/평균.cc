#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

int n;
double maxv = 0, total = 0;
vector<double> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxv = max(maxv, v[i]);
    }
    for (int i = 0; i < n; i++) {
        v[i] = v[i] / maxv * 100;
        total += v[i];
    }
    cout << total / n;
}