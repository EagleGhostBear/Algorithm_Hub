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

    cin >> n;
    n *= 5;
    n -= 400;
    cout << n << "\n";
    if (n == 100) {
        cout << "0";
    }
    else if (n < 100) {
        cout << "1";
    }
    else {
        cout << "-1";
    }
}