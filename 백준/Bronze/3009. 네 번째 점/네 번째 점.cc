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

unordered_map<int, int> um1, um2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;
        um1[a]++, um2[b]++;
    }
    for (auto now : um1) if (now.second == 1) cout << now.first << " ";
    for (auto now : um2) if (now.second == 1) cout << now.first;
}
/*

*/