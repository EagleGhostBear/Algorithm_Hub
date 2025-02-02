#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

string s;

bool solution(int idx) {
    string num1 = s.substr(0, idx), num2 = s.substr(idx);
    int val1 = 1, val2 = 1;

    for (auto c : num1) val1 *= (c - '0');
    for (auto c : num2) val2 *= (c - '0');

    if (val1 == val2) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    for (int i = 1; i < s.size(); i++) {
        if (solution(i)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}