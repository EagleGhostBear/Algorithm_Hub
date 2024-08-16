#include <iostream>

using namespace std;

int t;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        int total = 1;
        for (int j = 0; j < b; j++) {
            total *= a;
            total %= 10;
        }
        if (total == 0) {
            total = 10;
        }
        cout << total << "\n";
    }
}