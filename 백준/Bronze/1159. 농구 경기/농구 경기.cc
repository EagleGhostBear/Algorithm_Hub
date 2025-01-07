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

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v[int(s[0] - 'a')]++;
    }

    vector<char> tmp;
    for (int i = 0; i < 26; i++) {
        if (v[i] >= 5) {
            tmp.push_back(i + 'a');
        }
    }

    if (tmp.empty()) {
        cout << "PREDAJA";
    }
    else {
        sort(tmp.begin(), tmp.end());
        for (auto c : tmp) {
            cout << c;
        }
    }
}