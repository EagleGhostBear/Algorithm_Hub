#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string n;
    cin >> n;
    while (n != "0") {
        bool chk = true;
        int sz = n.size();
        for (int i = 0; i < sz / 2; i++) {
            if (n[i] != n[sz -1 - i]) {
                chk = false;
                break;
            }
        }
        if (chk) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
        cin >> n;
    }
}