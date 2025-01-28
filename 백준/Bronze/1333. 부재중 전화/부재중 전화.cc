#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n, l, d;
vector<int> music;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> l >> d;
    for(int i=0; i<n; i++){
        for(int j=0; j<l; j++){
            music.push_back(0);
        }
        for(int j=0; j<5; j++){
            music.push_back(1);
        }
    }
    
    int now = 0;
    bool chk = true;
    while(now < music.size()){
        if(music[now]){
            chk = false;
            cout << now;
            break;
        }
        else{
            now += (d);
        }
    }
    if(chk){cout << now;}
}