#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t;

int gcd(int a, int b) {
    while (b) { // 나머지가 0이 될때까지 시행
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int gcd_num = gcd(a, b);
        cout << a * b / gcd_num << "\n";
    }
}
/*

*/