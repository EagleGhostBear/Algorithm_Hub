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
    int n;
    vector<int> v;
};

int n, k;
node minv = { 100002, {} };
vector<int> visited(100001, 1e9);

void bfs() {
    queue<node> q;
    q.push({ n, {n} });
    visited[n] = 0;

    while (q.size()) {
        node now = q.front(); q.pop();

        if (now.n == k) {
            if (minv.n > visited[k]) {
                minv.n = visited[k];
                minv.v = now.v;
            }
            continue;
        }

        if (minv.n <= visited[now.n] + 1) continue;
        vector<int> tmp;
        if (2 * now.n <= 100000 && visited[2 * now.n] > visited[now.n] + 1) {
            visited[2 * now.n] = visited[now.n] + 1;
            tmp = now.v;
            tmp.push_back(2 * now.n);
            q.push({ 2 * now.n, tmp });
        }
        if (now.n + 1 <= 100000 && visited[now.n + 1] > visited[now.n] + 1) {
            visited[now.n + 1] = visited[now.n] + 1;
            tmp = now.v;
            tmp.push_back(now.n + 1);
            q.push({ now.n + 1, tmp });
        }
        if (now.n > 0 && visited[now.n - 1] > visited[now.n] + 1) {
            visited[now.n - 1] = visited[now.n] + 1;
            tmp = now.v;
            tmp.push_back(now.n - 1);
            q.push({ now.n - 1, tmp });
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;

    if (n < k) {
        bfs();
        cout << minv.n << "\n";
        for (auto c : minv.v) cout << c << " ";
    }
    else {
        cout << n - k << "\n";
        for (int i = n; i >= k; i--) {
            cout << i << " ";
        }
    }
}