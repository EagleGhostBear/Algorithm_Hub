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

int n;
unordered_map<string, int> um;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;
        if (state == "enter") um[name] = 1;
        else um[name] = 0;
    }

    vector<string> s;
    for (auto data : um) {
        if (data.second) s.push_back(data.first);
    }
    sort(s.begin(), s.end(), greater<string>());

    for (auto name : s) cout << name << "\n";
}