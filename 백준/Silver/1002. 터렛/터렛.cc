#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

typedef long long ll;

double t, a, b, c, d, e, f;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d >> e >> f;
        double len = sqrt(pow(d - a, 2) + pow(e - b, 2));

        if (a == d && b == e && c == f) {
            cout << "-1\n";
        }
        else if (len < max(c, f) - min(c, f) || len > c + f) {
            cout << "0\n";
        }
        else if (len == max(c, f) - min(c, f) || len == c + f) {
            cout << "1\n";
        }
        else {
            cout << "2\n";
        }
    }
}
/*
두원이 한점에서 접한다 = 1
두원이 두점에서 만난다 = 2
두원이 겹친다 = -1(무한대)
두원이 안만난다 = 0
*/