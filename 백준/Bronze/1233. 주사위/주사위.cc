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
vector<int> v(81, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int k=1; k<=c; k++){
                v[i+j+k]++;
            }
        }
    }
    
    int minv = 0, cnt = 0;
    for(int i=0; i<81; i++){
        if(v[i] > cnt){
            minv = i;
            cnt = v[i];
        }
    }
    cout << minv;
}