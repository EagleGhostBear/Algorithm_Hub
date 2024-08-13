#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

string s;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int cnt = 1;
    int total = 0;
    cin >> s;
    for (int i = s.size()-1; i > -1; i--) {
        char c = s[i];
        int nowv;
        if ('0' <= c && c <= '9') {
            nowv = c - '0';
        }
        else {
            nowv = c - 'A' + 10;
        }
        nowv *= cnt;
        total += nowv;
        cnt *= 16;
    }
    cout << total;
}