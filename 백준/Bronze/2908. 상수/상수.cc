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

int n1, n2;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    char tmp1 = s1[0], tmp2 = s2[0];
    s1[0] = s1[2], s2[0] = s2[2];
    s1[2] = tmp1, s2[2] = tmp2;
    n1 = stoi(s1), n2 = stoi(s2);
    
    if(n1 > n2) cout << n1;
    else cout << n2;
}