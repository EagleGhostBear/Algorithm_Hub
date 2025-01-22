#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int ans = 1;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(a == ans){
            ans = b;
        }
        else if(b == ans){
            ans = a;
        }
    }
    cout << ans;
}