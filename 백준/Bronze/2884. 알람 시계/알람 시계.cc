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

int h, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> h >> m;
    int total = h * 60 + m;
    total -= 45;
    if (total < 0) total += 24 * 60;
    cout << total / 60 << " " << total % 60;
}
/*

*/