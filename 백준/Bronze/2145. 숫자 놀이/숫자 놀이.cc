#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, k;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while (cin >> n) {
        if (!n) break;

        while (n >= 10) {
            string s = to_string(n);
            int num = 0;
            for (int i = 0; i < s.size(); i++) {
                num += (s[i] - '0');
            }
            n = num;
        }
        cout << n << "\n";
    }
}