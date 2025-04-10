#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        bool chk = true;
        int cnt = 0;
        string a, b;
        cin >> a >> b;
        vector<int> v(26);
        for (auto c : a) v[c - 'a']++, cnt++;
        for (auto c : b) {
            if (v[c - 'a']) v[c - 'a']--, cnt--;
            else {
                chk = false;
                break;
            }
        }
        if (chk && !cnt) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}