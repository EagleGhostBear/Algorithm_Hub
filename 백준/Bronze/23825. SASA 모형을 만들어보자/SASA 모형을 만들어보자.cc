#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    n /= 2;
    m /= 2;
    cout << min(n, m);
}