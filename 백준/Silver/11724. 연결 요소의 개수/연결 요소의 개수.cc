#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
int cnt = 0;
vector<vector<int>> v;
vector<int> chk;

void dfs(int now) {
    for (int i = 1; i <= n; i++) {
        if (v[now][i] == 0) {
            continue;
        }
        if (chk[i]) {
            continue;
        }
        chk[i] = 1;
        dfs(i);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    v.resize(n + 1, vector<int>(n+1));
    chk.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (chk[i]) { continue; }
        cnt += 1;
        dfs(i);
    }

    cout << cnt;
}