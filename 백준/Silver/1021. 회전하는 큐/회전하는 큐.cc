#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct node {
    int loc;
    int cnt;
};

int n, m, ans = 0, loc = 0;
vector<int> v;

node chk_left(int target) {
    int tmp_loc = loc;
    int cnt = 0;
    while (v[tmp_loc] != target) {
        tmp_loc--;
        if (tmp_loc < 0) tmp_loc = v.size() - 1;
        if (!v[tmp_loc]) continue;
        cnt++;
    }
    return { tmp_loc, cnt };
}
node chk_right(int target) {
    int tmp_loc = loc;
    int cnt = 0;
    while (v[tmp_loc] != target) {
        tmp_loc++;
        if (tmp_loc >= v.size()) tmp_loc = 0;
        if (!v[tmp_loc]) continue;
        cnt++;
    }
    return { tmp_loc, cnt };
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) v.push_back(i);
    for (int i = 0; i < m; i++) {
        int target;
        cin >> target;
        node left = chk_left(target);
        node right = chk_right(target);
        if (left.cnt <= right.cnt) {
            ans += left.cnt;
            loc = left.loc;
        }
        else {
            ans += right.cnt;
            loc = right.loc;
        }
        v[loc] = 0;
        if (i == m - 1) break;
        while (!v[loc]) {
            loc++;
            if (loc >= v.size()) loc = 0;
        }
    }
    cout << ans;
}