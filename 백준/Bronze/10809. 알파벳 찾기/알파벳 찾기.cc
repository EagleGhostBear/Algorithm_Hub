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
vector<int> idx(26, -1);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (idx[s[i] - 'a'] < 0) idx[s[i] - 'a'] = i;
    }
    for (auto c : idx) cout << c << " ";
}