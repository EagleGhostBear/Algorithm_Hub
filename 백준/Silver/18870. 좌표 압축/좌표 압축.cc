#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> cv;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cv = v;
    sort(cv.begin(), cv.end());
    cv.erase(unique(cv.begin(), cv.end()), cv.end());

    for (int i = 0; i < n; i++) {
        int now = v[i];
        int left = 0, right = cv.size() - 1;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (cv[mid] < now) {
                left = mid + 1;
                ans = mid + 1; // idx값이기 때문에 실제 개수는 +1
            }
            else {
                right = mid - 1;
            }
        }
        cout << ans << " ";
    }
}