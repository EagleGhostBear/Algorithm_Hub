#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int fir = v[0];

    sort(v.begin(), v.end(), greater<int>());
    
    if(fir == v[0]){
        cout << "S";
    }
    else{
        cout << "N";
    }
}