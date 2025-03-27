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

int n, m;
string url, pwd;
unordered_map<string, string> um;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> url >> pwd;
        um[url] = pwd;
    }

    for (int i = 0; i < m; i++) {
        cin >> url;
        cout << um[url] << "\n";
    }
}