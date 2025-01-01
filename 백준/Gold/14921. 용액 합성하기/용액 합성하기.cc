#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

typedef long long ll;

int n;
int ans = 1e9;
vector<int> v;

void solution(int idx) {
    int total = v[idx];

    int left = idx + 1;
    int right = n - 1;
    int mid = (left + right) / 2;

    while (left <= right) {
        mid = (left + right) / 2;
        if (abs(ans) > abs(total + v[mid])) { ans = total + v[mid]; }
        if (total + v[mid] == 0) {
            ans = 0;
            return;
        }
        else if (total + v[mid] < 0) {
            left = mid + 1;
        }
        else if(total + v[mid] > 0) {
            right = mid - 1;
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

    for (int i = 0; i < n; i++) {
        solution(i);
    }

    cout << ans;
}