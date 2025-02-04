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

int t, n;
ll ans = 0;
vector<int> a, b;
vector<int> v1, v2;
unordered_map<int, int> um;

void add1(int idx) {
    ll total = 0;
    for (int i = idx; i < a.size(); i++) {
        //if (t < total + a[i]) continue;
        total += a[i];
        v1.push_back(total);
    }
    return;
}
void add2(int idx) {
    ll total = 0;
    for (int i = idx; i < b.size(); i++) {
        //if (t < total + b[i]) continue;
        total += b[i];
        um[total]++;
        v2.push_back(total);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> n;
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < a.size(); i++) add1(i);
    for (int i = 0; i < b.size(); i++) add2(i);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (int i = 0; i < v1.size(); i++) {
        int left = 0;
        int right = v2.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (v1[i] + v2[mid] == t) {
                ans += um[v2[mid]];
                //cout << v1[i] << " " << v2[mid] << ": +" << um[v2[mid]] << endl;
                break;
            }
            else if (v1[i] + v2[mid] < t) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }

    cout << ans;
}