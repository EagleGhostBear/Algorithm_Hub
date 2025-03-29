#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t, n;
unordered_map<string, int> um;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        um.clear();
        for (int i = 0; i < n; i++) {
            string name, category;
            cin >> name >> category;
            um[category]++;
        }
        int ans = 1;
        for (auto data : um) ans *= (data.second + 1);
        cout << ans - 1 << "\n";
    }
}