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

string s;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    v.resize(10, 0);
    for (auto c : s) {
        int num = c - '0';
        v[num]++;
    }

    v[6] += v[9];
    if (v[6] % 2) v[6] = v[6] / 2 + 1;
    else v[6] = v[6] / 2;
    v[9] = v[6];

    int ans = 0;
    for (auto num : v) ans = max(ans, num);
    cout << ans;
}