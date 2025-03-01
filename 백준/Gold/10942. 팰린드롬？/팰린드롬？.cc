#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, m;
vector<int> v;
vector<pair<int, int>> dp1; // dp1[idx] = 홀수 좌우 허용 범위
vector<pair<int, int>> dp2; // dp2[idx] = 짝수 좌우 허용 범위

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n + 1);
    dp1.resize(n + 1, pair<int, int>());
    dp2.resize(n, pair<int, int>());

    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int idx = 1; idx <= n; idx++) {
        int gap = 0;
        while (1 <= idx - gap && idx + gap <= n && v[idx - gap] == v[idx + gap]) gap++;
        gap--;
        dp1[idx] = { idx - gap, idx + gap };
    }

    for (int idx = 1; idx < n; idx++) {
        int gap = 0;
        while (1 <= idx - gap && idx + gap + 1 <= n && v[idx - gap] == v[idx + gap + 1]) gap++;
        gap--;
        if (gap == -1) dp2[idx] = { idx + 1, idx }; // 팰린드롬 없는 경우
        else dp2[idx] = { idx - gap, idx + gap + 1 };
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        int len = to - from + 1;
        int mid = (from + to) / 2;
        if (len % 2) { // 홀수 길이
            if (dp1[mid].first <= from && to <= dp1[mid].second) cout << "1\n";
            else cout << "0\n";
        }
        else { // 짝수 길이
            if (dp2[mid].first <= from && to <= dp2[mid].second) cout << "1\n";
            else cout << "0\n";
        }
    }
}
/*
최악 : 2000 * 2000 = 4,000,000
*/