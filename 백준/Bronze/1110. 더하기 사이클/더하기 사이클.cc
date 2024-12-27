#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int now = n, cnt = 0;
    while (n != now || !cnt) {
        int num1 = now / 10, num2 = now % 10;
        if (now < 10) {
            now = num2 * 10 + num2;
        }
        else {
            now = num2*10 + (num1 + num2) % 10;
        }
        cnt += 1;
    }
    cout << cnt;
}