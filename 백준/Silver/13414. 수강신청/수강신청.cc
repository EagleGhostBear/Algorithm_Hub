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
    bool operator()(pair<string, int> left, pair<string, int> right) {
        if (left.second < right.second) return true;
        if (left.second > right.second) return false;
        return false;
    }
};

int k, l;
unordered_map<string, int> um;
vector<pair<string, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> k >> l;
    int cnt = 1;
    for (int i = 0; i < l; i++) {
        string s;
        cin >> s;
        um[s] = cnt++;
    }

    for (auto data : um) v.push_back({ data.first, data.second });

    sort(v.begin(), v.end(), compare());

    for (int i = 0; i < k; i++) {
        if (i > v.size() - 1) break;
        cout << v[i].first << "\n";
    }
}