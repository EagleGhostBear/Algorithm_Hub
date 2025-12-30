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
int m, n, x, y;

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
        cin >> m >> n >> x >> y;
        int num = x;
        int lcm = m * n / gcd(m, n);
        while (num <= lcm && num % n != y % n) num += m;

        if (num <= lcm) cout << num << "\n";
        else cout << "-1\n";
    }
}
/*
0을 시작으로 생각해서 나머지 연산
*/