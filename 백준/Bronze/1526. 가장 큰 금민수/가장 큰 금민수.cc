#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    while(1){
        string s = to_string(n);
        bool chk = true;
        for(auto c : s){
            if(c != '4' && c != '7'){
                chk = false;
            }
        }
        if(chk){
            cout << s;
            break;
        }
        n--;
    }
}