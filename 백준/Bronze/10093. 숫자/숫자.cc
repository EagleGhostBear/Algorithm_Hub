#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    long long a, b;
    cin >> a >> b;
    long long cnt = abs(b - a);
    if (cnt != 0) {
        cnt -= 1;
    }
    long long minv = min(a, b);
    cout << cnt << "\n";
    for (long long i = 1; i <= cnt; i++) {
        cout << minv + i << " ";
    }
}