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

int n;
vector<int> v(5);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int val = v[0];
    int cnt = 0;
    while (cnt < 3) {
        cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (!(val % v[i])) { cnt++; }
        }
        val++;
    }
    cout << val - 1;
}