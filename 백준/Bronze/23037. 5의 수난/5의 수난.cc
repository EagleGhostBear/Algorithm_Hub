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
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += pow(n % 10, 5);
        n /= 10;
    }

    cout << total;
}