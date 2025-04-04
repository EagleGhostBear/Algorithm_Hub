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

ll a, b, c;
unordered_map<ll, ll> um;
vector<ll> v;

ll solution(ll num) {
    if (num == 0) return 0;
    if (num == 1) return a % c;

    ll ret = solution(num / 2) % c;
    // 홀수
    if (num % 2) return (ret * ret % c) * a % c;
    // 짝수
    return ret * ret % c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    cout << solution(b);
}