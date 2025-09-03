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

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        ans += (s[i] - '0');
    }
    cout << ans;
}
/*

*/