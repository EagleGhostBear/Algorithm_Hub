#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

vector<int> cnt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cnt.resize(26, 0);
    while (cin >> s) {
        for (auto c : s) {
            cnt[c - 'a']++;
        }
    }

    vector<int> max_val;
    int max_cnt = 0;
    for (int i = 0; i < 26; i++) {
        if (max_cnt < cnt[i]) {
            max_val.clear();
            max_val.push_back(i);
            max_cnt = cnt[i];
        }
        else if (max_cnt == cnt[i]) {
            max_val.push_back(i);
        }
    }

    for (auto num : max_val) {
        cout << char(num + 'a');
    }
}