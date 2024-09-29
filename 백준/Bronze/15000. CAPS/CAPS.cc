#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        s[i] -= 32;
    }

    cout << s;
}