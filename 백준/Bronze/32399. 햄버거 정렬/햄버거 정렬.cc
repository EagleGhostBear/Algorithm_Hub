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

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int prev;
    if (s[0] == '(') prev = 0;
    else if (s[0] == '1') prev = 1;
    else if (s[0] == ')') prev = 2;
    int cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        int now;
        if (s[i] == '(') now = 0;
        else if (s[i] == '1') now = 1;
        else if (s[i] == ')') now = 2;
        if (now - prev > 0) cnt++;
        prev = now;
    }
    if (cnt == 3) cout << 0;
    else cout << 2 - cnt;
}