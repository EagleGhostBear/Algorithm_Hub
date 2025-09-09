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
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.assign(301, 4);
    for (int i = 250; i < 275; i++) v[i] = 3;
    for (int i = 275; i < 300; i++) v[i] = 2;
    v[300] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << v[a] << " ";
    }
}
/*

*/