#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
vector<int> v;
vector<int> path;
int visited[9] = { 0 };
unordered_map<string, bool> um;

void dfs(int level) {
    if (level == m) {
        string tmp = "";
        for (auto s : path) {
            tmp += v[s];
        }
        if (um[tmp]) {
            return;
        }
        um[tmp] = true;
        for (auto s : path) {
            cout << v[s] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!path.empty() && path.back() > i) {
            continue;
        }
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
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    dfs(0);
}