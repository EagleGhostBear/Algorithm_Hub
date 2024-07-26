#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int dat[26] = { 0 };

int main(int argc, char** argv) {
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int tmp = s[i];
        dat[tmp - int('a')] += 1;
    }

    for (int i = 0; i < 26; i++) {
        cout << dat[i] << " ";
    }
}