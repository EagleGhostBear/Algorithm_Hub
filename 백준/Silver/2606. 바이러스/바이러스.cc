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

int n, m, ans = 0;
vector<vector<int>> v;
vector<int> visited;

void bfs() {
    queue<int> q;
    q.push(1);
    visited[1] = 1;

    while (q.size()) {
        int now = q.front(); q.pop();

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (visited[next]) continue;
            ans++;
            visited[next] = 1;
            q.push(next);
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    v.resize(n + 1, vector<int>());
    visited.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    bfs();

    cout << ans;
}