#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int t, n;
double minv = 1e9;
vector<pair<int, int>> v;

void solution(int idx, int cnt, int total_row, int total_col) {
    if (idx == n) {
        if (cnt) { return; }
        double now = sqrt(pow(total_row, 2) + pow(total_col, 2));
        minv = min(minv, now);
        return;
    }
    if (cnt) {
        solution(idx + 1, cnt - 1, total_row - v[idx].first, total_col - v[idx].second);
    }
    solution(idx + 1, cnt, total_row + v[idx].first, total_col + v[idx].second);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //소수점 7자리까지만 출력
    cout << fixed;
    cout.precision(7);

    cin >> t;
    while(t--){
        cin >> n;
        minv = 1e9;
        v.clear();
        v.resize(n, make_pair(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        solution(0, n / 2, 0, 0);
        cout << minv << "\n";
    }
}