#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
int v[12] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
vector<int> path;

void bfs(int total) {
    if (path.size() == 2) {
        if (total == n) {
            if (cnt != 0) {
                cout << ", ";
            }
            cout << v[path[0]] << " " << v[path[1]];
            cnt++;
        }

        return;
    }
    for (int i = 0; i < 12; i++) {
        if (!path.empty() && path.back() >= i) {
            continue;
        }
        path.push_back(i);
        bfs(total + v[i]);
        path.pop_back();
    }
}

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cnt = 0;
        cin >> n;
        cout << "Pairs for " << n << ": ";
        for (int i = 0; i < 12; i++) {
            path.clear();
            path.push_back(i);
            bfs(v[i]);
        }
        cout << "\n";
    }
}