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

int n, k;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        b *= 100;
        c *= 10;
        v.push_back({ b + c + d, a });
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    int score = 0;
    pair<int, int> cnt = { -1, 1 }; // 금은동, 개수
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == cnt.first) {
            cnt.second++;
        }
        else {
            score += cnt.second;
            cnt = { v[i].first, 1 };
        }
        if (v[i].second == k) {
            cout << score;
            break;
        }
    }
}
/*
*/