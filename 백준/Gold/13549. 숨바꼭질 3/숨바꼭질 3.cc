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

int n, k;
vector<int> v(100001, -1);

void bfs() {
    queue<int> q;
    q.push(n);

    while (q.size()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) next = now * 2;
            else if (i == 1) next = now + 1;
            else next = now - 1;

            if (next < 0 || next > 100000) continue;

            if (i == 0) {
                if (v[next] >= 0 && v[next] <= v[now]) continue;
                v[next] = v[now];
                q.push(next);
            }
            else {
                if (v[next] >= 0 && v[next] <= v[now] + 1) continue;
                v[next] = v[now] + 1;
                q.push(next);
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    v[n] = 0;

    bfs();

    cout << v[k];
}