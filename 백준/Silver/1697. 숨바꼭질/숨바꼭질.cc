#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int n, k;

int v[100001] = { 0 };
queue<int> q;

void bfs() {
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == k) {
            cout << v[k];
            exit(0);
        }

        for (int i = 0; i < 3; i++) {
            int next;
            if (i == 0) { // -1
                next = now - 1;
            }
            else if (i == 1) { // +1
                next = now + 1;
            }
            else { // *2
                next = now * 2;
            }

            if (next < 0 || next > 100000) {
                continue;
            }

            if (v[next] != 0 && v[next] <= v[now] + 1) {
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

    cin >> n >> k;

    q.push(n);

    bfs();
}