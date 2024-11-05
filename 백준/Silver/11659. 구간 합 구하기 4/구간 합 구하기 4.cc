#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (i) {
            v[i] += v[i - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            cout << v[b - 1] << "\n";
        }
        else {
            cout << v[b - 1] - v[a - 2] << "\n";
        }
    }
}