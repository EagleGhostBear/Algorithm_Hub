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

struct compare {
    bool operator()(pair<ll, ll> left, pair<ll, ll> right) {
        if (left.first < right.first) return true;
        if (left.first > right.first) return false;
        return false;
    }
};
struct compare2 {
    bool operator()(pair<ll, ll> left, pair<ll, ll> right) {
        if (left.first == right.first) return true;
        if (left.first != right.first) return false;
        return false;
    }
};

ll n, ans = 0;
vector<vector<ll>> v;
vector<pair<ll, ll>> dat1, dat2;

void solution(pair<ll, ll> p) {
    ll target = p.first * -1;
    ll left = 0;
    ll right = dat2.size() - 1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (dat2[mid].first == target) {
            ans += (p.second * dat2[mid].second);
            return;
        }
        else if (dat2[mid].first < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(4, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 4; j++) {
            cin >> v[j][i];
        }
    }

    for (ll i = 0; i < n; i++) { // 32,000,000
        for (ll j = 0; j < n; j++) {
            dat1.push_back({ v[0][i] + v[1][j], 1 });
            dat2.push_back({ v[2][i] + v[3][j], 1 });
        }
    }

    sort(dat1.begin(), dat1.end(), compare());
    sort(dat2.begin(), dat2.end(), compare());

    pair<ll, ll> tmp = { 1e9, 0 }; // [값 : index정보]
    for (ll i = 0; i < dat1.size(); i++) {
        if (dat1[i].first == tmp.first) {
            dat1[tmp.second].second++;
        }
        else {
            tmp = { dat1[i].first, i };
        }
    }
    tmp = { 1e9, 0 }; // [값 : index정보]
    for (ll i = 0; i < dat2.size(); i++) {
        if (dat2[i].first == tmp.first) {
            dat2[tmp.second].second++;
        }
        else {
            tmp = { dat2[i].first, i };
        }
    }

    dat1.erase(unique(dat1.begin(), dat1.end(), compare2()), dat1.end());
    dat2.erase(unique(dat2.begin(), dat2.end(), compare2()), dat2.end());

    for (ll i = 0; i < dat1.size(); i++) {
        solution(dat1[i]);
    }

    cout << ans;
}