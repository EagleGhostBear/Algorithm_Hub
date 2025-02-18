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
vector<int> v = { 1, 1, 2, 2, 2, 8 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(int i=0; i<6; i++){
        cin >> n;
        cout << v[i] - n << " ";
    }
}