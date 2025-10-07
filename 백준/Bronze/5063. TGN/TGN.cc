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

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        int r, e, c;
        cin >> r >> e >> c;
        int ad1 = r;
        int ad2 = e - c;
        if (ad1 < ad2) cout << "advertise\n";
        else if (ad1 > ad2) cout << "do not advertise\n";
        else cout << "does not matter\n";
    }
}