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

int t;
string tmp;
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while (t--) {
        cin >> tmp;
        if (tmp == "push") {
            int n;
            cin >> n;
            s.push(n);
        }
        else if (tmp == "pop") {
            if (s.empty()) cout << "-1\n";
            else cout << s.top() << "\n", s.pop();
        }
        else if (tmp == "size") cout << s.size() << "\n";
        else if (tmp == "empty") {
            if (s.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (tmp == "top") {
            if (s.empty()) cout << "-1\n";
            else cout << s.top() << "\n";
        }
    }
}