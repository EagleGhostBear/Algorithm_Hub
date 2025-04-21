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

vector<int> v(26);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string tmp = "CAMBRIDGE";
    for(int i=0; i<tmp.size(); i++){
        v[int(tmp[i]) - int('A')]++;
    }
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(v[int(s[i]) - int('A')]) continue;
        cout << s[i];
    }
}