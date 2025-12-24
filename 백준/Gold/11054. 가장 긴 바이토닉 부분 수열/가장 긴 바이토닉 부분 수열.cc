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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) { cout << "1"; return 0; }
    vector<int> nums(n), dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j > -1; j--) {
            if (nums[i] > nums[j]) dp1[i] = max(dp1[i], dp1[j] + 1); // 오름차순
            if (nums[n - 1 - i] > nums[n - 1 - j]) dp2[n - 1 - i] = max(dp2[n - 1 - i], dp2[n - 1 - j] + 1); // 내림차순
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) { // 양끝에 최소 1개는 있어야 바이토닉이 되기 때문
        int left = 0, right = 0;
        for (int j = i - 1; j > -1; j--) if (nums[j] < nums[i]) left = max(left, dp1[j]);
        for (int j = i + 1; j < n; j++) if (nums[j] < nums[i]) right = max(right, dp2[j]);
        ans = max(ans, left + right + 1);
    }
    cout << ans;
}