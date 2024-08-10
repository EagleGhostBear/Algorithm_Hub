#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int k;
vector<int> v;
vector<int> path;

void bfs(int level) {
    if (level == 6) {
        for (auto s : path) {
            cout << v[s] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < k; i++) {
        if (!path.empty() && path.back() >= i) {
            continue;
        }

        path.push_back(i);

        bfs(level + 1);

        path.pop_back();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        cin >> k;
        if (k == 0) {
            break;
        }

        v.clear();
        path.clear();
        for (int i = 0; i < k; i++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        bfs(0);
        cout << "\n";
    }
}