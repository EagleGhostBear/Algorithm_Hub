#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
int path[8] = { 0 };

void dfs(int level) {
    if (level == m) {
        for (int i = 0; i < m; i++) {
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        path[level] = i;
        dfs(level + 1);
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    dfs(0);
}