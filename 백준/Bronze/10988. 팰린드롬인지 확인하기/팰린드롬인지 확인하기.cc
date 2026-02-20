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

    string s;
    cin >> s;
    int sz = s.size() / 2;
    for (int i = 0; i < sz; i++) {
        if (s[i] != s[s.size() - 1 - i]) { cout << "0"; return 0; }
    }
    cout << "1";
}