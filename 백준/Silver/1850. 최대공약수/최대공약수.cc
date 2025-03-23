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

ll a, b;

ll gcd(ll a, ll b){
    while(b){
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    ll ans = gcd(a, b);
    for(int i=0; i<ans; i++) cout << "1";
}