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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int ans = 0;
    for(int i=0; i<5; i++){
        cin >> n;
        if(n <= 40) ans += 40;
        else ans += n;
    }
    cout << ans / 5;
}
/*

*/