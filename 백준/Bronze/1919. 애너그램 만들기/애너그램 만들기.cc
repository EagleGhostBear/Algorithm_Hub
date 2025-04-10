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

vector<int> v1(26), v2(26);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    for (auto c : a) v1[c - 'a']++;
    for (auto c : b) v2[c - 'a']++;

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += abs(v1[i] - v2[i]);
    }
    cout << ans;
}