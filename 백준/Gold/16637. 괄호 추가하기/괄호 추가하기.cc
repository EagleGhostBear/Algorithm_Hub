#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, ans = -1 * pow(2, 31);
vector<int> num;
vector<char> v;

void solution(int idx, int level, vector<int> tmp) {
    if (level == 0) {
        vector<int> v1 = num;
        vector<char> v2 = v;
        for (auto i : tmp) {
            if (v2[i] == '+') v1[i] += v1[i + 1];
            else if (v2[i] == '-') v1[i] -= v1[i + 1];
            else if (v2[i] == '*') v1[i] *= v1[i + 1];
            v2[i] = '+';
            v1[i + 1] = 0;
        }
        int total = v1[0];
        for (int i = 0; i < v2.size(); i++) {
            if (v2[i] == '+') total += v1[i + 1];
            else if (v2[i] == '-') total -= v1[i + 1];
            else if (v2[i] == '*') total *= v1[i + 1];
        }
        ans = max(ans, total);
        return;
    }

    for (int i = idx + 1; i < v.size(); i++) {
        tmp.push_back(i);
        solution(i + 1, level - 1, tmp);
        tmp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2) v.push_back(s[i]);
        else num.push_back(s[i] - '0');
    }
    if (num.size() == 1) ans = max(ans, num[0]);

    for (int i = 1; i <= 5; i++) solution(-1, i, {});
    cout << ans;
}