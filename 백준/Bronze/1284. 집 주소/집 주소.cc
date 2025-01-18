#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (1) {
        cin >> s;
        if (s == "0") { break; }
        int total = 1;
        for (auto c : s) {
            if (c == '0') { total += 5; }
            else if (c == '1') { total += 3; }
            else { total += 4; }
        }
        cout << total << "\n";
    }
}