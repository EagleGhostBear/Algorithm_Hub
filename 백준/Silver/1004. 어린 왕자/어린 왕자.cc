#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct node {
    int x;
    int y;
    int r;
};

int t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    for (int k = 0; k < t; k++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int cx, cy, r, chk1, chk2;
            cin >> cx >> cy >> r;

            if (pow(x1 - cx, 2) + pow(y1 - cy, 2) <= pow(r, 2)) {
                chk1 = -1;
            }
            else {
                chk1 = 1;
            }

            if (pow(x2 - cx, 2) + pow(y2 - cy, 2) <= pow(r, 2)) {
                chk2 = -1;
            }
            else {
                chk2 = 1;
            }

            if (chk1 * chk2 < 0) {
                //cout << cx << "," << cy << ": " << r << endl;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
/*
원을 기준으로 1개의 점은 내부, 1개의 점은 외부 서로 나뉘어있으면 된다.
*/