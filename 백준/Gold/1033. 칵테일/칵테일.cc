#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

struct node {
    ll to;
    ll p;
    ll q;
};

ll n, a, b, p, q;
vector<vector<node>> v;
vector<int> visited;
vector<ll> ans;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solution(int idx) {
    for (int i = 0; i < v[idx].size(); i++) {
        int next_idx = v[idx][i].to;
        if (visited[next_idx]) { continue; }

        ans[next_idx] = ans[idx] * v[idx][i].q;

        for (int j = 0; j < n; j++) {
            if (visited[j]) {
                ans[j] *= v[idx][i].p;
            }
        }

        visited[next_idx] = 1;
        solution(next_idx);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; // 1 <= n <= 10
    v.resize(n, vector<node>());
    visited.resize(n, 0);
    ans.resize(n, 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> p >> q;
        v[a].push_back({ b, p, q });
        v[b].push_back({ a, q, p });
    }

    visited[0] = 1;
    solution(0);

    int total_gcd = ans[0];
    for (int i = 1; i < n; i++) {
        total_gcd = gcd(total_gcd, ans[i]);
    }

    for (auto num : ans) {
        cout << num / total_gcd << " ";
    }
}