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

vector<int> v(3);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    
    while (1) {
        cin >> v[0] >> v[1] >> v[2];
        if (!v[0] && !v[1] && !v[2]) break;
        unordered_map<int, int> um;
        um[v[0]]++;
        um[v[1]]++;
        um[v[2]]++;
        sort(v.begin(), v.end());
        if (v[2] >= v[0] + v[1]) cout << "Invalid\n";
        else {
            if (um.size() == 1) cout << "Equilateral\n";
            else if (um.size() == 2) cout << "Isosceles\n";
            else cout << "Scalene\n";
        }
    }
}