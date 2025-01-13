#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string a, b;
vector<ll> v1, v2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        v1.push_back(a[i] - '0');
    }
    for (int i = 0; i < b.size(); i++) {
        v2.push_back(b[i] - '0');
    }

    ll total = 0;
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            total += (v1[i] * v2[j]);
        }
    }

    cout << total;
}