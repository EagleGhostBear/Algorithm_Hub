#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

string s1, s2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    if(s1.size() >= s2.size()){
        cout << "go";
    }
    else{
        cout << "no";
    }
}