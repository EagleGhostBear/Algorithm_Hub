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

int n, k;
vector<int> v(11);

void solution(string s, int level) {
    if (level == 0) {
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (i == 0 && s[j] - '0' == 0) continue;
            string next = s;
            next[i] = s[j];
            next[j] = s[i];
            int val = stoi(next);
            if (v[level - 1] >= val) continue;
            v[level - 1] = val;
            solution(next, level - 1);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    solution(to_string(n), k);
    if (v[0]) cout << v[0];
    else cout << "-1";
}
/*

*/