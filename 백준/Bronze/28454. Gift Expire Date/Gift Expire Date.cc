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

int convert(string s) {
    int num = stoi(s.substr(0, 4));
    num *= 100;
    num += stoi(s.substr(5, 2));
    num *= 100;
    num += stoi(s.substr(8, 2));
    return num;
}

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> n;
    int base = convert(s);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int now = convert(s);
        if (base <= now) ans++;
    }
    cout << ans;
}
/*

*/