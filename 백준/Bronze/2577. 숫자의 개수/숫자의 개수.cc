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

int a, b, c;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    string s = to_string(a * b * c);
    v.resize(10, 0);
    for (auto c : s) {
        int num = c - '0';
        v[num]++;
    }
    for (auto c : v) cout << c << "\n";
}