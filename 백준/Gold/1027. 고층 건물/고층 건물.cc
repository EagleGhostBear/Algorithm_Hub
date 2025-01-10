#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v;
vector<int> cnt;

double solution(int left, int right) {
    double left_x = left;
    double left_y = v[left];
    double right_x = right;
    double right_y = v[right];

    return (right_y - left_y) / (right_x - left_x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    cnt.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        double slab = -1000000001;
        for (int j = i + 1; j < n; j++) {
            double now = solution(i, j);
            //cout << "(" << i << "," << j << "):" << now << " ";
            if (now > slab) {
                cnt[i]++;
                cnt[j]++;
                slab = now;
            }
        }
    }

    int ans = 0;
    for (auto num : cnt) {
        ans = max(ans, num);
    }

    cout << ans;
}
/*
기울기 양수 = 큰 건물
기울기 음수 = 작은 건물
*/