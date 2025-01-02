#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);
    
    if (s.size() == 1 && s[0] == ' ') {
        cout << "0";
        return 0;
    }

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' && i != 0 && i != s.size() - 1) {
            cnt++;
        }
    }

    cout << cnt + 1;
}