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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, last;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            cin >> m;
            last = m;
            q.push(m);
        }
        else if (s == "pop") {
            if (q.size()) { cout << q.front() << "\n"; q.pop(); }
            else cout << "-1\n";
        }
        else if (s == "size") cout << q.size() << "\n";
        else if (s == "empty") {
            if (q.size()) cout << "0\n";
            else cout << "1\n";
        }
        else if (s == "front") {
            if (q.size()) cout << q.front() << "\n";
            else cout << "-1\n";
        }
        else if (s == "back") {
            if (q.size()) cout << last << "\n";
            else cout << "-1\n";
        }
    }
}