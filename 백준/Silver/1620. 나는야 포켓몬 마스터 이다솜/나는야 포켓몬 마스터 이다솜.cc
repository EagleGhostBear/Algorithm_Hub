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

bool is_number(char c) {
    if ('0' <= c && c <= '9') return true;
    else return false;
}

int n, m;
unordered_map<string, int> poket_name;
vector<string> poket_number;
vector<string> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    poket_number.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        poket_name[name] = i;
        poket_number[i] = name;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (is_number(s[0])) ans.push_back(poket_number[stoi(s)]);
        else ans.push_back(to_string(poket_name[s]));
    }

    for (auto c : ans) {
        cout << c << "\n";
    }
}