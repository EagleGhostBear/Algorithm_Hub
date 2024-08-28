#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

int t;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int total = 0;
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        total += n;
    }
    cout << total;
}