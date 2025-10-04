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
#include <iomanip>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(10001, 0);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[tmp]++;
    }
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << i << "\n";
        }
    }
}