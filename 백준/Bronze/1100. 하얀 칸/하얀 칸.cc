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

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int ans = 0;
    for (int i = 0; i < 8; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 8; j++) {
            if (tmp[j] == 'F' && (i + j) % 2 == 0) {
                ans++;
            }
        }
    }

    cout << ans;
}