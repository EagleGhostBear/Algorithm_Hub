#include <iostream>
#include <vector>
#include <algorithm>
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

    cin >> n;
    v.resize(201, 0);
    for (int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v[tmp + 100]++;
    }
    cin >> k;
    cout << v[k + 100];
}