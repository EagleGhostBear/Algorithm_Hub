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

int n, idx1, idx2;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "KBS1") idx1 = i;
        else if (s == "KBS2") idx2 = i;
    }

    if (idx1 > idx2) idx2++;
    for (int i = 0; i < idx1; i++) cout << "1";
    for (int i = 0; i < idx1; i++) cout << "4";
    for (int i = 0; i < idx2; i++) cout << "1";
    for (int i = 0; i < idx2 - 1; i++) cout << "4";
}
/*
*/