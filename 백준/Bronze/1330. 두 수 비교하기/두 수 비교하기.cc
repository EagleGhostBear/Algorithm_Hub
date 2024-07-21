#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << ">";
    }
    else if (a < b) {
        cout << "<";
    }
    else {
        cout << "==";
    }
}