#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v(26, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    for (auto c : s) {
        if (int(c) > int('Z')) {
            v[int(c) - 32 - int('A')]++;
        }
        else {
            v[int(c) - int('A')]++;
        }
    }

    int idx = -1, val = -1, cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (v[i] > val) {
            idx = i;
            val = v[i];
            cnt = 1;
        }
        else if (v[i] == val) {
            cnt++;
        }
    }

    if (cnt != 1) {
        cout << "?";
    }
    else {
        cout << char(idx + int('A'));
    }
}