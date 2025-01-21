#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int d, h, w;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> d >> h >> w;
    double tmp = sqrt(pow(h, 2) + pow(w, 2));
    double a = d / tmp;
    cout << int(h * a) << " " << int(w * a);
}