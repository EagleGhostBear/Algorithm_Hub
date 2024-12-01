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

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin >> s;
    for(int i=0; i<n-1; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<s.size(); j++){
            if(s[j] != tmp[j]){
                s[j] = '?';
            }
        }
    }
    
    cout << s;
}