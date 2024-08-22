#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1;; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        int n1 = 3 * n;
        int n4;
        if (n1 % 2 == 0) {
            n4 = n / 2;
            cout << i << ". even " << n4 << "\n";
        }
        else {
            n4 = (n - 1) / 2;
            cout << i << ". odd " << n4 << "\n";
        }
    }
}