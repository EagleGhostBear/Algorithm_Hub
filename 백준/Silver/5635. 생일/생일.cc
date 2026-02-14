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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    pair<string, int> maxP = { "", 0 }, minP = { "", 99999999 };
    while (n--) {
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        int date = (y * 10000) + (m * 100) + d;
        if (maxP.second < date) maxP = { name, date };
        if (minP.second > date) minP = { name, date };
    }
    cout << maxP.first << "\n" << minP.first;
}