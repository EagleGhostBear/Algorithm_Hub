#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

typedef long long ll;

ll minv, maxv;
vector<ll> v(1000001);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> minv >> maxv;
    int cnt = 0;
    for (ll i = 2; i * i <= maxv; i++) { // 제곱수 i^2 (i는 2부터 시작)
        // i^2 의 배수들을 구하는데 min값 보다 큰 최소 배수 n 을 구한다.
        ll n = minv / (i * i); // minv보다 크거나 같은 i^2의 배수를 찾기 위한 초기값

        if (minv % (i * i)) { n++; } // minv가 i^2로 나누어 떨어지지 않으면 올림 처리

        while (n * i * i <= maxv) { // i^2의 배수가 maxv를 넘지 않는 동안
            v[n * i * i - minv] = 1; // n * i^2가 제곱수의 배수임을 표시
            n++; // 다음 i^2의 배수로 이동
        }
    }

    for (int i = 0; i <= maxv - minv; i++) {
        if (v[i] == 0) { cnt++; } // 1로 표기안된 i들은 어떤 제곱수의 배수도 아닌것이다.
    }

    cout << cnt;
}
/*
1보다 큰 제곱수 부터 시작해(4, 9, 16, 25, ...)
해당 제곱수에 n을 곱해가면서 max값보다 작은 배수를 다 표기한다.(4*1, 4*2, 4*3, 4*4, 4*5, ...)
*/