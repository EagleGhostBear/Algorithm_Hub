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

string a, c;
char b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    if (b == '+') {
        if (a.size() == c.size()) {
            a[0] = '2';
            cout << a;
        }
        else if (a.size() > c.size()) {
            a[a.size() - c.size()] = '1';
            cout << a;
        }
        else if (a.size() < c.size()) {
            c[c.size() - a.size()] = '1';
            cout << c;
        }
    }
    else if (b == '*') {
        cout << "1";
        for (int i = 0; i < a.size() - 1; i++) cout << "0";
        for (int i = 0; i < c.size() - 1; i++) cout << "0";
    }
}
/*

*/