#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    cin.ignore();
    cout << fixed;
    cout.precision(2);
    while (t--) {
        string s, now;
        getline(cin, s);
        double num = 0;
        int idx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                now = s.substr(idx, i - idx);
                if (now == "@") num *= 3;
                else if (now == "%") num += 5;
                else if (now == "#") num -= 7;
                else num = stod(s.substr(idx, i - idx));
                idx = i + 1;
            }
        }
        now = s.substr(idx);
        if (now == "@") num *= 3;
        else if (now == "%") num += 5;
        else if (now == "#") num -= 7;
        cout << num << "\n";
    }
}