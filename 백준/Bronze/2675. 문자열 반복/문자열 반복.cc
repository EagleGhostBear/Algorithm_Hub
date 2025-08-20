#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
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
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < s.size(); i++) for (int j = 0; j < n; j++) {
            cout << s[i];
        }
        cout << "\n";
    }
}
/*

*/