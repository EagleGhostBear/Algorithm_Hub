#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> b >> c >> d;
    cout << a*56 + b*24 + c*14 + d*6;
}