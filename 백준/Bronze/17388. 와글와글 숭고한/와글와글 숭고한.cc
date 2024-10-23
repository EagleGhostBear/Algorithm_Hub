#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<int> v(3);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }

    if (v[0] + v[1] + v[2] >= 100) {
        cout << "OK";
    }
    else if (v[0] < v[1] && v[0] < v[2]) {
        cout << "Soongsil";
    }
    else if (v[1] < v[0] && v[1] < v[2]) {
        cout << "Korea";
    }
    else {
        cout << "Hanyang";
    }
}