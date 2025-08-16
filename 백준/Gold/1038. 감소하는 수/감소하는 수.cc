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

int n;
vector<string> v;
priority_queue<ll, vector<ll>, greater<ll>> pq;

void solution() {
    while (pq.size()) {
        ll now = pq.top();
        pq.pop();

        string s = to_string(now);
        v.push_back(s);

        for (int i = s[0] - '0' + 1; i < 10; i++) {
            string next = to_string(i) + s;
            pq.push(stoll(next));
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < 10; i++) pq.push(i);
    solution();
    if (n < v.size()) cout << v[n];
    else cout << "-1";
}
/*
9876543210 가능한 마지막 숫자
*/