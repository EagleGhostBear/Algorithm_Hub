#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    if (pow(a - d, 2) + pow(b - e, 2) < pow(c + f, 2)) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}