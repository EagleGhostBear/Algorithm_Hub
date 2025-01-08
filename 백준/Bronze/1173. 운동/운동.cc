#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int ans_cnt = 0, total_cnt = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c, d, e, stat;
    cin >> a >> b >> c >> d >> e;
    stat = b;
    if (stat + d > c) {
        cout << "-1";
        return 0;
    }
    while (ans_cnt < a) {
        if (stat + d <= c) {
            stat += d;
            ans_cnt++;
        }
        else if (stat - e > b) {
            stat -= e;
        }
        else {
            stat = b;
        }
        total_cnt++;
    }
    cout << total_cnt;
}