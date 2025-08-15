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

struct node {
    int num;
    int g, s, b;
};

struct compare {
    bool operator()(node left, node right) {
        if (left.g > right.g) return true;
        if (left.g < right.g) return false;

        if (left.s > right.s) return true;
        if (left.s < right.s) return false;

        if (left.b > right.b) return true;
        if (left.b < right.b) return false;

        return false;
    }
};

int n, k;
vector<node> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({ a, b, c, d });
    }
    sort(v.begin(), v.end(), compare());
    int score = 0;
    pair<node, int> cnt = { {-1, -1, -1, -1}, 1}; // 금은동, 개수
    for (int i = 0; i < v.size(); i++) {
        if (v[i].g == cnt.first.g && v[i].s == cnt.first.s && v[i].b == cnt.first.b) {
            cnt.second++;
        }
        else {
            score += cnt.second;
            cnt = { {-1, v[i].g, v[i].s, v[i].b}, 1 };
        }
        if (v[i].num == k) {
            cout << score;
            break;
        }
    }
}
/*
*/