#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> v;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (tmp == "push") {
            int num;
            cin >> num;
            v.push_back(num);
        }
        else if (tmp == "pop") {
            if (v.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << v[v.size() - 1] << "\n";
                v.pop_back();
            }
        }
        else if (tmp == "size") {
            cout << v.size() << "\n";
        }
        else if (tmp == "empty") {
            if (v.empty()) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else if (tmp == "top") {
            if (v.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << v[v.size() - 1] << "\n";
            }
        }
    }
}