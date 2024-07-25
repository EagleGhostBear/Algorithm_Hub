#include <iostream>
#include <string>

using namespace std;

int t;

int main(int argc, char** argv) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        int a = s[0] - '0';
        int b = s[2] - '0';
        cout << a + b << "\n";
    }
}