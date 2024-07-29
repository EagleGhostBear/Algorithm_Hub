#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, m;
int v[9] = { 0, };
vector<int> path;

void dfs(int level) {
    if (level == m) {
        for (auto s : path) {
            cout << s << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!path.empty() && i <= path.back()) { continue; }
        path.push_back(i);

        dfs(level + 1);

        path.pop_back();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    dfs(0);
}