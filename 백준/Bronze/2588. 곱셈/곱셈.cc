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
    
    int a, b, tmp;
    cin >> a >> b;
    tmp = b;
    cout << a * (tmp%10) << "\n";
    tmp /= 10;
    cout << a * (tmp%10) << "\n";
    tmp /= 10;
    cout << a * (tmp%10) << "\n";
    cout << a * b << "\n";
}