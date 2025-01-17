#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int y = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        y += (tmp / 30) * 10 + 10;
        m += (tmp / 60) * 15 + 15;
    }

    if (y == m) {
        cout << "Y M ";
    }
    else if (y > m) {
        cout << "M ";
    }
    else {
        cout << "Y ";
    }
    cout << min(y, m);
}