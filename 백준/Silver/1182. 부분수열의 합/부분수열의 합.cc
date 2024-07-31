#include <iostream>
#include <vector>

using namespace std;

int n, s;
int total = 0;
vector<int> v;
vector<int> path;

void bfs(int level, int val) {
    if (val == s && level != 0) {
        total += 1;
    }
    else if (level == n) {
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!path.empty() && i <= path.back()) { continue; }

        path.push_back(i);
        val += v[i];

        bfs(level + 1, val);

        path.pop_back();
        val -= v[i];
    }
}

int main(int argc, char** argv) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    bfs(0, 0);

    cout << total;
}