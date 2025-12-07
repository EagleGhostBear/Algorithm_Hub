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

int n, x;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp < x) v.push_back(tmp);
    }
    for (auto c : v) cout << c << " ";
}