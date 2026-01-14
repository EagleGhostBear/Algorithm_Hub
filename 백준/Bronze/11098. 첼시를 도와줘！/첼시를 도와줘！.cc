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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        pair<int, string> ans = { 0, "" };
        int price;
        string name;
        for (int i = 0; i < n; i++) {
            cin >> price >> name;
            if (ans.first < price) ans = { price, name };
        }
        cout << ans.second << "\n";
    }
}