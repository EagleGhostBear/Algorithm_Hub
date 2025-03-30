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
unordered_map<string, vector<string>> um1;
unordered_map<string, string> um2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    while (n--) {
        vector<string> member;
        string team;
        int cnt;
        cin >> team >> cnt;
        while (cnt--) {
            string name;
            cin >> name;
            member.push_back(name);
            um2[name] = team;
        }
        sort(member.begin(), member.end());
        um1[team] = member;
    }
    while (m--) {
        int type;
        string s;
        cin >> s >> type;
        if (type) cout << um2[s] << "\n";
        else {
            for (auto name : um1[s]) cout << name << "\n";
        }
    }
}