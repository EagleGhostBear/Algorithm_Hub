#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int h, m, s, d;
    cin >> h >> m >> s >> d;
    cout << (h + (m + (s + d) / 60) / 60) % 24 << " " << (m + (s + d) / 60) % 60 << " " << (s + d) % 60;
    return 0;
}