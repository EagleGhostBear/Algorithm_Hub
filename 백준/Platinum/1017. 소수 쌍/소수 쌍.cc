#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v, ans, left_idx, right_idx, match_right;
vector<bool> p, used_right;
vector<vector<int>> l;

bool dfs(int idx) {
    for (int i = 0; i < l[idx].size(); i++) {
        int right_i = l[idx][i];
        if (used_right[right_i]) continue;
        used_right[right_i] = true;
        if (match_right[right_i] == -1 || dfs(match_right[right_i])) {
            match_right[right_i] = idx;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    p.assign(2000, true);
    p[0] = false, p[1] = false;
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 2; i <= 1000; i++) for (int j = 2; i * j < 2000; j++) {
        p[i * j] = false;
    }
    for (int i = 0; i < n; i++) {
        if (v[0] % 2) {
            if (v[i] % 2) left_idx.push_back(i);
            else right_idx.push_back(i);
        }
        else {
            if (v[i] % 2) right_idx.push_back(i);
            else left_idx.push_back(i);
        }
    }
    l.resize(left_idx.size(), vector<int>());
    for (int i = 0; i < left_idx.size(); i++) for (int j = 0; j < right_idx.size(); j++) {
        if (p[v[left_idx[i]] + v[right_idx[j]]]) l[i].push_back(j);
    }
    for (int i = 0; i < l[0].size(); i++) {
        int right_i = l[0][i];
        int cnt = 1;
        match_right.assign(right_idx.size(), -1);
        match_right[right_i] = 0;
        for (int j = 1; j < left_idx.size(); j++) {
            used_right.assign(right_idx.size(), false);
            used_right[right_i] = true;
            if (dfs(j)) cnt++;
        }
        if (cnt == n / 2) ans.push_back(v[right_idx[right_i]]);
    }
    if (ans.size()) {
        sort(ans.begin(), ans.end());
        for (auto c : ans) cout << c << " ";
    }
    else cout << "-1";
}