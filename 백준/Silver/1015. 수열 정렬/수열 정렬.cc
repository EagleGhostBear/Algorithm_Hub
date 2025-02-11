#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second < b.second) return true;
        else if (a.second == b.second && a.first < b.first) return true;
        else return false;
    }
};

int n;
vector<pair<int, int>> a; // a.first = idx, a.second = val
vector<int> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n, make_pair(0, 0));
    p.resize(n);
    for (int i = 0; i < n; i++) {
        a[i].first = i;
        cin >> a[i].second;
    }

    sort(a.begin(), a.end(), compare());

    for (int i = 0; i < n; i++) {
        p[a[i].first] = i;
    }
    for (auto num : p) cout << num << " ";
}
/*
B[P[0]] = A[0]
B[P[1]] = A[1]
B[P[2]] = A[2]

B[P[0]] = 2(0)
B[P[1]] = 3(1)
B[P[2]] = 1(2)

B[P[2]] = 1(2)
B[P[0]] = 2(0)
B[P[1]] = 3(1)

1. val 기준으로 정렬
2. p[idx] = 0, 1, 2, 3 순서대로 박음

B[1] = 2
B[2] = 3
B[0] = 1

P = { 1, 2, 0 };
B = { 1, 2, 3 };
*/