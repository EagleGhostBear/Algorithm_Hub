#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> v, ans(3);

void solution(int idx) {
    int left = idx + 1;
    int right = n - 1;

    int mid = (left + right) / 2;
    int minv = v[idx] + v[mid]; // 최초값
    int sv_mid = mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int total = v[idx] + v[mid];

        if (abs(minv) > abs(total)) {
            minv = total;
            sv_mid = mid;
        }

        if (total == 0) {
            break;
        }
        else if (total < 0) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (abs(minv) < abs(ans[2])) {
        ans[2] = minv;
        ans[0] = v[idx];
        ans[1] = v[sv_mid];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ans[2] = 2000000000;

    for (int i = 0; i < n - 1; i++) {
        solution(i);
    }

    cout << ans[0] << " " << ans[1];
}