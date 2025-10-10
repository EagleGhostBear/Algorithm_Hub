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
#include <iomanip>

using namespace std;

typedef long long ll;

int n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;
    a -= 1, b -= 1;
    pair<int, int> cnt = { 2, 1 };
    while (a / cnt.first != b / cnt.first) {
        cnt.first <<= 1;
        cnt.second++;
    }
    cout << cnt.second;
}