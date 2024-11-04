#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    int total = 0;
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        total += tmp;
    }
    if(total%3==0){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}