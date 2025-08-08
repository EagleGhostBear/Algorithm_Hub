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

struct node {
    int idx;
    int level;
    int visited;
};

int n, total = 0, ans = 1000;
vector<int> p;
vector<vector<int>> v;

bool is_chk(int visited) { // visited의 1 들이 모두 연결되어 있는지 확인
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (visited & (1 << i)) { // 최초 1 위치찾기
            q.push(i);
            visited &= ~(1 << i);
            break;
        }
    }
    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if ((visited & (1 << next)) == 0) continue;
            visited &= ~(1 << next);
            q.push(next);
        }
    }
    if (visited == 0) return true;
    else return false;
}

void cal(int now) {
    ans = min(ans, abs(total - 2 * now));
    return;
}

void sel(int idx, int level, int cnt, int visited) {
    if (level == 0) {
        int bitmask = (1 << n) - 1;
        if (is_chk(visited) && is_chk(~visited & bitmask)) cal(cnt);
        return;
    }

    for (int i = idx + 1; i < n; i++) {
        sel(i, level - 1, cnt + p[i], visited | (1 << i));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    p.resize(n);
    v.resize(n, vector<int>());
    for (int i = 0; i < n; i++) cin >> p[i], total += p[i];
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp - 1);
            v[tmp - 1].push_back(i);
        }
    }

    for (int i = 1; i <= 5; i++) {
        sel(-1, i, 0, 0);
    }

    if (ans == 1000) cout << "-1";
    else cout << ans;
}
/*
최대 10개 지역이기 때문에 5개까지만 확인하면 된다.
*/