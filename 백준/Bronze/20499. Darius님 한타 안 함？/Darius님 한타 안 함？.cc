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

    string data;
    cin >> data;
    string tmp = "";
    for (auto c : data) {
        if (c == '/') {
            v.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            tmp += c;
        }
    }
    v.push_back(stoi(tmp));
    if (v[1] == 0 || v[0] + v[2] < v[1]) {
        cout << "hasu";
    }
    else {
        cout << "gosu";
    }

}