#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> v;
vector<int> path;
int visited[9] = { 0 };

void dfs(int now, int level) {
    if (level == m) {
        for (auto s : path) {
            cout << s << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < v[now].size(); i++) {
        int tmp = v[now][i];
        if (visited[tmp] == 1) {
            continue;
        }
        visited[tmp] = 1;
        path.push_back(tmp);
        dfs(tmp, level + 1);
        visited[tmp] = 0;
        path.pop_back();
    }
}

int main(int argc, char** argv) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        vector<int> row;
        for (int j = 1; j <= n; j++) {
            row.push_back(j);
        }
        v.push_back(row);
    }

    dfs(0, 0);
}