#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    ll cnt = 0;
    while(n != 1){
        if(n%2 == 0){
            n/=2;
        }
        else{
            n+=1;
        }
        cnt++;
    }
    cout << cnt;
}