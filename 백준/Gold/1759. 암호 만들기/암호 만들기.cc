#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int l, c;
int cnt1 = 0;
int cnt2 = 0;
vector<char> v;
vector<char> path;

void bfs(int level) {
    if (level == l) {
        if (cnt1 < 1 || cnt2 < 2) {
            return;
        }
        for (auto s : path) {
            cout << v[s];
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < c; i++) {
        if (!path.empty() && path.back() >= i) {
            continue;
        }

        path.push_back(i);
        if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u') {
            cnt1++;
            bfs(level + 1);
            cnt1--;
        }
        else {
            cnt2++;
            bfs(level + 1);
            cnt2--;
        }
        path.pop_back();
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    bfs(0);
}