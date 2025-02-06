#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

string s;

int solution(string n) {
    int val = 0, cnt = 1;
    for (int i = n.size()-1; i > -1; i--) {
        val += ((n[i] - '0') * cnt);
        cnt *= 2;
    }
    return val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int start = s.size() % 3;
    if(start){ cout << solution(s.substr(0, start)); }
    for (int i = start; i < s.size(); i+=3) {
        cout << solution(s.substr(i, 3));
    }
}