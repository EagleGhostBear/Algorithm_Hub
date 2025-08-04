#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    b += c;
    if (b / 60) {
        a += (b / 60);
        b %= 60;
    }
    if (a >= 24) a -= 24;
    cout << a << " " << b;
}