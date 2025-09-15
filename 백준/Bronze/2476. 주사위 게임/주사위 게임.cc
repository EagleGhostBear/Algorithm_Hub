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
#include <iomanip>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int max_prize = 0;

    for (int i = 0; i < n; ++i) {
        int d1, d2, d3;
        cin >> d1 >> d2 >> d3;

        int prize;

        if (d1 == d2 && d2 == d3) {
            prize = 10000 + d1 * 1000;
        }
        else if (d1 == d2 || d1 == d3) {
            prize = 1000 + d1 * 100;
        }
        else if (d2 == d3) {
            prize = 1000 + d2 * 100;
        }
        else {
            int max_eye = max({ d1, d2, d3 });
            prize = max_eye * 100;
        }

        if (prize > max_prize) {
            max_prize = prize;
        }
    }

    cout << max_prize;
}
/*

*/