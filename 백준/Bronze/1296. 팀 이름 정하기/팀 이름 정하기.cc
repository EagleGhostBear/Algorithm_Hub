#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string name;
int n;
vector<string> v;
int max_idx = -1, max_val = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> name;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        string tmp = name + v[i];
        vector<int> cnt(4, 0);

        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == 'L') { cnt[0]++; }
            else if (tmp[j] == 'O') { cnt[1]++; }
            else if (tmp[j] == 'V') { cnt[2]++; }
            else if (tmp[j] == 'E') { cnt[3]++; }
        }

        int total = 1;
        for (int j = 0; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                total *= (cnt[j] + cnt[k]);
            }
        }
        total %= 100;
        if (max_val < total) {
            max_val = total;
            max_idx = i;
        }
    }
    cout << v[max_idx];
}