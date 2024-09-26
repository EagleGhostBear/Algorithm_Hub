#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

bool cut_tree(int h) {
    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] <= h) { break; }
        total += (v[i] - h);
        if (total >= m) { return true; }
    }
    return false;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), greater<int>());

    int left = 0, right = v.front();
    int ans;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (cut_tree(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
}