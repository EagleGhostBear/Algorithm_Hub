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

vector<pair<int, int>> v;
int a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a >> b >> c;
    for(int i=0; i<=6; i++) v.push_back({0, i});
    v[a].first++;
    v[b].first++;
    v[c].first++;
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    if(v[0].first == 3) cout << 10000 + v[0].second * 1000;
    else if(v[0].first == 2) cout << 1000 + v[0].second * 100;
    else cout << v[0].second * 100;
}
/*

*/