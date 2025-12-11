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

int n;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int tmp;
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (s == "push_back") {
            int tmp;
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (s == "pop_front") {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (s == "pop_back") {
            if (dq.empty()) cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (s == "size") {
            cout << dq.size() << "\n";
        }
        else if (s == "empty") {
            if (dq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (s == "front") {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.front() << "\n";
        }
        else if (s == "back") {
            if (dq.empty()) cout << "-1\n";
            else cout << dq.back() << "\n";
        }
    }
}