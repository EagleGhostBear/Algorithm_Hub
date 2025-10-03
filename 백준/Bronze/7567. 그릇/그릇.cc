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

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int n = 10;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) n += 5;
        else n += 10;
    }
    cout << n;
}