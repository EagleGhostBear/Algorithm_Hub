#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string a, b, s;
int val = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    int a_idx = a.size() - 1, b_idx = b.size() - 1;
    while (a_idx > -1 || b_idx > -1) {
        if (a_idx > -1) {
            val += a[a_idx] - '0';
            a_idx--;
        }
        if (b_idx > -1) {
            val += b[b_idx] - '0';
            b_idx--;
        }
        if (val > 1) {
            val -= 2;
            s += to_string(val);
            val = 1;
        }
        else {
            s += to_string(val);
            val = 0;
        }
    }
    if (val) { s += to_string(val); }

    bool chk = false;
    for (int i = s.size()-1; i > -1; i--) {
        if (s[i] == '1') { chk = true; }
        if (chk) { cout << s[i]; }
    }
    if (!chk) { cout << "0"; }
}