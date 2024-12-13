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

int n;
vector<vector<int>> dp; // dp[N번째 자리][0 ~ 9] = 개수

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;
    cout << min(min(abs(x), abs(x-w)), min(abs(y), abs(y-h)));
}