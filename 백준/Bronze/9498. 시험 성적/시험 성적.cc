#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if(n >= 90) cout << "A";
    else if(n >= 80) cout << "B";
    else if(n >= 70) cout << "C";
    else if(n >= 60) cout << "D";
    else cout << "F";
}