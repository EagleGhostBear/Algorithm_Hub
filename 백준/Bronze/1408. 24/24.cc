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
#include <iomanip>

using namespace std;

typedef long long ll;

int convert(string s) {
    int time = 0;
    time += (stoi(s.substr(0, 2)) * 3600);
    time += (stoi(s.substr(3, 2)) * 60);
    time += stoi(s.substr(6, 2));
    return time;
}

void restore(int time) {
    cout << setw(2) << setfill('0') << time / 3600 << ":";
    time %= 3600;
    cout << setw(2) << setfill('0') << time / 60 << ":";
    time %= 60;
    cout << setw(2) << setfill('0') << time;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;
    int total = convert(b) - convert(a);
    if (total < 0) total += (24 * 3600);
    restore(total);
}
/*

*/