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

int n, k;
vector<vector<int>> v; // v[학년][성별]

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    v.resize(6, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        int s, y;
        cin >> s >> y;
        v[y - 1][s]++;
    }

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            if (v[i][j] % k) ans += 1;
            ans += (v[i][j] / k);
        }
    }
    cout << ans;
}