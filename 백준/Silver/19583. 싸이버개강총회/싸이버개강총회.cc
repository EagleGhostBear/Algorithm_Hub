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

string s, e, q;
unordered_map<string, pair<int, int>> um;

string convert_time(string time) {
    return time.substr(0, 2) + time.substr(3, 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> e >> q;
    s = convert_time(s);
    e = convert_time(e);
    q = convert_time(q);
    string t, n;
    while (cin >> t >> n) {
        t = convert_time(t);
        if (t <= s) um[n].first = 1;
        if (e <= t && t <= q) um[n].second = 1;
    }

    int ans = 0;
    for (auto data : um) {
        if (data.second.first && data.second.second) ans++;
    }
    cout << ans;
}