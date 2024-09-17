#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        int total = 0;
        int cnt = 1;
        for (int j = tmp.size() - 1; j > -1; j--) {
            total += (int(tmp[j]) - int('0')) * cnt;
            cnt *= 2;
        }
        cout << total << "\n";
    }
}