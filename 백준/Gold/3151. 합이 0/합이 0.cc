#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
long long ans = 0;
vector<int> v;
vector<vector<int>> idx_cnt(20001, vector<int>());

int find_cnt(int target, int val) {
    int left = 0;
    int right = idx_cnt[val].size() - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (idx_cnt[val][mid] == target) {
            break;
        }
        else if (idx_cnt[val][mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return idx_cnt[val].size() - mid;
}

void solution(int idx, int total) {
    int left = idx;
    int right = n-1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (v[mid] + total == 0) { // idx - right 범위 내에서 v[mid]와 같은 값들이 몇개인지 찾아야함
            int cnt = find_cnt(idx, v[mid] + 10000);
            ans += cnt;
            return;
        }
        else if (v[mid] + total > 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return;
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

    for (int i = 0; i < n; i++) {
        idx_cnt[v[i] + 10000].push_back(i);
    }

    // 거꾸로 하면서 해당 좌표 기준 같은값이 몇개인지..?

    for (int i = 0; i < n; i++) { // 100,000,000 * log(n)
        for (int j = i + 1; j < n; j++) {
            solution(j + 1, v[i] + v[j]);
        }
    }

    cout << ans;
}