#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<char> v(4);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a >> v[i];
        for (int j = 0; j < a; j++) {
            cout << v[i];
        }
        cout << "\n";
    }
}