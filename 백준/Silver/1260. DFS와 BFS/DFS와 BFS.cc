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

int n, m, p;
vector<vector<int>> v;
vector<int> visited;

void dfs(int now) {
    cout << now << " ";
    visited[now] = 1;
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (visited[next]) continue;
        dfs(next);
    }
}

void bfs() {
    vector<int> visited(n + 1);
    queue<int> q;
    q.push(p);
    visited[p] = 1;

    while (q.size()) {
        int now = q.front(); q.pop();
        cout << now << " ";

        for (int i = 0; i < v[now].size(); i++) {
            int next = v[now][i];
            if (visited[next]) continue;
            visited[next] = 1;
            q.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    v.resize(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    visited.resize(n + 1);
    dfs(p);
    cout << "\n";
    visited.resize(n + 1);
    bfs();
}