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

int t, n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int tmp;
        for (int i = 0; i < n; i++) { // 세준 : S
            cin >> tmp;
            pq1.push(tmp);
        }
        for (int i = 0; i < m; i++) { // 세비 : B
            cin >> tmp;
            pq2.push(tmp);
        }

        while (pq1.size() && pq2.size()) {
            if (pq1.top() < pq2.top()) pq1.pop();
            else if (pq1.top() > pq2.top()) pq2.pop();
            else pq2.pop();
        }
        if (pq1.size()) cout << "S\n";
        else if (pq2.size()) cout << "B\n";
        else cout << "C\n";
    }
}