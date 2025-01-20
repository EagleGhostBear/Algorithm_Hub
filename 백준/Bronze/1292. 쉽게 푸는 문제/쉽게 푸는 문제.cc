#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int total = 0;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    for (int i = 1; i < 46; i++) {
        for (int j = 0; j < i; j++) {
            v.push_back(i);
        }
    }
    for (int i = a; i <= b; i++) {
        total += v[i-1];
    }
    cout << total;
}