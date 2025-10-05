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

int n, m, ans = 0;
vector<int> left_idx, right_idx, match_right;
vector<bool> used_right;
vector<vector<int>> l;

bool dfs(int idx) {
    for (auto right_i : l[idx]) {
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

    cin >> n >> m;
    left_idx.resize(n);
    right_idx.resize(m);
    l.resize(n, vector<int>());
    for (int i = 0; i < n; i++) left_idx[i] = i;
    for (int i = 0; i < m; i++) right_idx[i] = i;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            int tmp;
            cin >> tmp;
            l[i].push_back(tmp - 1);
        }
    }

    for (auto first_left : left_idx) { // left 그룹에서 최초 매칭 시킬 항목
        match_right.assign(right_idx.size(), -1);
        if (l[first_left].size()) {
            int first_right = l[first_left][0]; // 어차피 밀어내기를 하기 때문에 1개로 픽스
            int cnt = 1;
            match_right[first_right] = first_left;
            for (auto left_i : left_idx) {
                if (left_i == first_left) continue;
                used_right.assign(right_idx.size(), false);
                used_right[first_right] = 1;
                if (dfs(left_i)) cnt++;
            }
            ans = max(ans, cnt);
        }
        for (auto first_right : l[first_left]) {

        }
    }
    cout << ans;
}