#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a+b)%c << "\n";
    cout << ((a%c) + (b%c))%c << "\n";
    cout << (a*b)%c << "\n";
    cout << ((a%c) * (b%c))%c << "\n";
}