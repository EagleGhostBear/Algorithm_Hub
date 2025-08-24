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

int n, k;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= 16777216; i <<= 1) {
        v.push_back(i);
    }
    for (int i = v.size() - 1; i > -1; i--) {
        if(k != 1) {
            if (n >= v[i]) {
                n -= v[i];
                k--;
            }
        }
    }

    if (n == 0) {
        cout << "0";
    }
    else {
        for (int i = v.size() - 1; i > -1; i--) {
            if (k == 1) {
                if (v[i] >= n && n > v[i] / 2) {
                    cout << v[i] - n;
                    break;
                }
            }
        }
    }
}
/*

*/