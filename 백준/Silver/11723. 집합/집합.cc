#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<bool> v(21);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int a;
        cin >> s;
        if (s == "all") v.assign(21, true);
        else if (s == "empty") v.assign(21, false);
        else {
            cin >> a;
            if (s == "add") v[a] = true;
            else if (s == "remove") v[a] = false;
            else if (s == "toggle") v[a] = !v[a];
            else {
                if (v[a]) cout << "1\n";
                else cout << "0\n";
            }
        }
    }
}
/*
*/