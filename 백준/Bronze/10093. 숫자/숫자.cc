#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b;
    cin >> a >> b;
    int cnt = abs(b - a);
    if (cnt != 0) {
        cnt -= 1;
    }
    int minv = min(a, b);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) {
        cout << minv + i << " ";
    }
}