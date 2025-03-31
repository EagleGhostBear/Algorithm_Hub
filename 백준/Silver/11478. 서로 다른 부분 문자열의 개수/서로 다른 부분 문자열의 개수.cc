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
unordered_map<string, bool> um;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (int sz = 1; sz <= s.size(); sz++) {
        for (int i = 0; i < s.size(); i++) {
            if (i + sz > s.size()) break;
            um[s.substr(i, sz)] = true;
        }
    }
    cout << um.size();
}