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
    vector<int> nums(n), lis1, lis2, dp1(n), dp2(n);
    int maxLen1 = 0, maxLen2 = 0;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
        if (lis1.empty() || lis1.back() < nums[i]) lis1.push_back(nums[i]);
        else {
            int left = 0, right = lis1.size() - 1;
            int mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (left == right) break;
                else if (nums[i] <= lis1[mid]) right = mid;
                else left = mid + 1;
            }
            lis1[mid] = nums[i];
        }
        if (lis2.empty() || lis2.back() < nums[n - 1 - i]) lis2.push_back(nums[n - 1 - i]);
        else {
            int left = 0, right = lis2.size() - 1;
            int mid = 0;
            while (left <= right) {
                mid = (left + right) / 2;
                if (left == right) break;
                else if (nums[n - 1 - i] <= lis2[mid]) right = mid;
                else left = mid + 1;
            }
            lis2[mid] = nums[n - 1 - i];
        }
        maxLen1 = max(maxLen1, (int)lis1.size());
        maxLen2 = max(maxLen2, (int)lis2.size());
        dp1[i] = maxLen1;
        dp2[i] = maxLen2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp1[i] + dp2[n - 1 - i]  - 1);
    }
    cout << ans;
}