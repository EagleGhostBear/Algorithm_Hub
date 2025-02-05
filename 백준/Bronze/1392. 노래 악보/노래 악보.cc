#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

int n, q;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    v.resize(n+1);
    v[0] = 0;
    for (int i=1; i<=n; i++) cin >> v[i];
    
    for (int i=1; i<=n; i++) v[i] += v[i-1];
    
    for(int i=0; i<q; i++){
        int tmp;
        cin >> tmp;
        cout << distance(v.begin(), upper_bound(v.begin(), v.begin()+(n+1), tmp)) << "\n";
    }
}