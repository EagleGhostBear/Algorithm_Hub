#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
vector<int> v1;
vector<int> v2;
vector<int> ans;

bool solution(int target) {
    int left = 0;
    int right = m - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (v2[mid] == target) {
            return false;
        }
        else if (v2[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v1.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        v2.push_back(tmp);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < n; i++) {
        if (solution(v1[i])) {
            ans.push_back(v1[i]);
        }
    }

    cout << ans.size() << "\n";
    for (auto s : ans) {
        cout << s << " ";
    }
}