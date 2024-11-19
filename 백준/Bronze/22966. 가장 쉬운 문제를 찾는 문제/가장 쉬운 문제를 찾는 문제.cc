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
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin.ignore();

    string min_name;
    int min_val = 10;
    for (int i = 0; i < n; i++) {
        string tmp;
        getline(cin, tmp);
        int num = tmp.back() - '0';

        if (min_val > num) {
            min_val = num;
            min_name = tmp.substr(0, tmp.size() - 2);
        }
    }

    cout << min_name;
}