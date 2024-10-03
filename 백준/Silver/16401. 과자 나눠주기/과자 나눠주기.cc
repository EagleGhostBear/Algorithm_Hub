#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
vector<int> v;

bool solution(int target) {
    int cnt = 0;
    for (auto val : v) {
        int now = val / target;
        if (now < 1) {
            return false;
        }
        else {
            cnt += now;
            if (cnt >= m) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), greater<int>());

    int left = 1;
    int right = v.front();
    int ans = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (solution(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (ans < 0) {
        cout << 0;
    }
    else {
        cout << ans;
    }
}