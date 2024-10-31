#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long ll;

int s, m, l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> s >> m >> l;
    int n = s * 1 + m * 2 + l * 3;
    if(n>=10){
        cout << "happy";
    }
    else{
        cout << "sad";
    }
    
}