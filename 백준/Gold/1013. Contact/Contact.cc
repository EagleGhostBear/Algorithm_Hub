#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <regex>

using namespace std;

typedef long long ll;

int t;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        string s;
        cin >> s;
        regex pattern("(100+1+|01)+");
        if (regex_match(s, pattern)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}
/*
(100+1+ | 01)+ = "100+1+" 와 "01" 만 반복 가능하다는 의미
문자열을 순서대로 탐험하면서 둘중 하나를 만족하는지 확인해야함
*/