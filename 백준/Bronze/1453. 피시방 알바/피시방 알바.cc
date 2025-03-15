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

int n, ans = 0;
int v[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(v[tmp]) ans++;
        v[tmp] = 1;
    }
    cout << ans;
}