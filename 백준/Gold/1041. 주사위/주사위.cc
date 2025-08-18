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

ll n;
vector<int> v(6);
vector<ll> len = { 150, 150, 150 };
vector<vector<int>> con = { {0,1,1,1,1,0},{1,0,1,1,0,1},{1,1,0,0,1,1},{1,1,0,0,1,1},{1,0,1,1,0,1},{0,1,1,1,1,0} };

void solution(int l, int center, int idx, ll total, int level) {
    if (level == 0) {
        len[l] = min(len[l], total);
        return;
    }

    for (int i = idx + 1; i < 6; i++) {
        if (con[center][i] == 0) continue;
        if (idx != -1 && con[idx][i] == 0) continue;
        solution(l, center, i, total + v[i], level - 1);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int t = 0, ans = 250;
    for (int i = 0; i < 6; i++) cin >> v[i], t += v[i];
    if (n == 1) {
        for (int i = 0; i < 6; i++) ans = min(ans, t - v[i]);
        cout << ans;
        return 0;
    }
    for (int i = 0; i < 3; i++) for (int j = 0; j < 6; j++) {
        solution(i, j, -1, v[j], i);
    }
    len[0] *= (4 * (n - 2) + 5 * (n - 2) * (n - 2));
    len[1] *= (4 + 8 * (n - 2));
    len[2] *= 4;
    cout << len[0] + len[1] + len[2];
}
/*
3면 = 4
2면 = 4 + 8 * (n - 2)
1면 = 4 * (n - 2) + 5 * (n - 2) * (n - 2)
*/