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

int n, m, a, b;
vector<vector<int>> v;
vector<int> visited;

void bfs(int s) {
    queue<pair<int, int>> q;
    q.push({ s, 1 });
    visited[s] = 1;

    while (q.size()) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < v[now.first].size(); i++) {
            int next = v[now.first][i];
            if (visited[next]) continue;
            visited[next] = now.second + 1;
            q.push({ next, now.second + 1 });
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n + 1, vector<int>());
    visited.resize(n + 1);
    cin >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(a);

    if (visited[b]) cout << visited[b] - 1;
    else cout << "-1";
}