#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    int total = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            v.pop_back();
        }
        else {
            v.push_back(tmp);
        }
    }

    while (!v.empty()) {
        total += v[v.size() - 1];
        v.pop_back();
    }

    cout << total;
}