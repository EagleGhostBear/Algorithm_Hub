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

struct point {
    int x, y;
    bool operator<(point other) const {
        if (x < other.x) return true;
        if (x > other.x) return false;

        if (y < other.y) return true;
        if (y > other.y) return false;
        return false;
    }
};

int n;
vector<int> v;
vector<pair<point, point>> line;

int ccw(point a, point b, point c) {
    int v = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}

bool intersect(point a, point b, point c, point d) {
    if (b < a) swap(a, b);
    if (d < c) swap(c, d);

    int ab_c = ccw(a, b, c);
    int ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a);
    int cd_b = ccw(c, d, b);

    // 일직선(colinear)인 경우
    if (ab_c == 0 && ab_d == 0) {
        // 구간 겹치면 교차 (끝점 접촉 포함)
        return !(d < a || b < c); // 즉, c <= b && a <= d
    }

    // 일반적인 교차 판정 (끝점 접촉 포함)
    return (ab_c * ab_d <= 0) && (cd_a * cd_b <= 0);
}

int find(int idx) {
    if (v[idx] == idx) return idx;
    return v[idx] = find(v[idx]);
}

void unite(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
    if (root_a != root_b) {
        v[root_a] = root_b;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n + 1);
    for (int i = 0; i < n; i++) v[i] = i;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        line.push_back({ {a, b}, {c, d} });
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (intersect(line[i].first, line[i].second, line[j].first, line[j].second)) {
            unite(i, j);
        }
    }

    unordered_map<int, int> um;
    int maxv = 0;
    for (int i = 0; i < n; i++) um[find(i)]++;
    for (auto data : um) maxv = max(maxv, data.second);
    cout << um.size() << "\n" << maxv;
}
/*

*/