#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int f, s, g, u, d;

vector<int> v;
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            int next;
            if (i == 0) { // U
                next = now + u;
            }
            else { // D
                next = now - d;
            }

            if (next < 0 || next >= f) {
                continue;
            }

            if (v[next] <= v[now] + 1) {
                continue;
            }

            v[next] = v[now] + 1;
            q.push(next);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> f >> s >> g >> u >> d;
    s -= 1;
    g -= 1;

    for (int i = 0; i < f; i++) {
        v.push_back(1e9);
    }

    v[s] = 0;
    q.push(s);

    bfs();

    if (v[g] == 1e9) {
        cout << "use the stairs";
    }
    else {
        cout << v[g];
    }
}