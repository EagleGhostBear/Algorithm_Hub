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

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int val = n;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i << "\n";
            n /= i;
        }
    }
}
/*

*/