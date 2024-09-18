#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int sc;
        cin >> name >> sc;
        cout << name << " ";
        if (97 <= sc) {
            cout << "A+\n";
        }
        else if (90 <= sc) {
            cout << "A\n";
        }
        else if (87 <= sc) {
            cout << "B+\n";
        }
        else if (80 <= sc) {
            cout << "B\n";
        }
        else if (77 <= sc) {
            cout << "C+\n";
        }
        else if (70 <= sc) {
            cout << "C\n";
        }
        else if (67 <= sc) {
            cout << "D+\n";
        }
        else if (60 <= sc) {
            cout << "D\n";
        }
        else {
            cout << "F\n";
        }
    }
}