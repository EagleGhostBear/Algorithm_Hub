#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int a, b;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> a >> b;
    if(a * (100 - b) / 100 >= 100){
        cout << "0";
    }
    else{
        cout << "1";
    }
}