#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int n;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tmp;
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> tmp;
        sum += tmp;
    }
    cout << sum*5;
    return 0;
}