#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <string>
#include <cmath>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;

string s1, s2;

int solution(string num) {
    string tmp = "";
    for (int i = num.size() - 1; i > -1; i--) {
        tmp += num[i];
    }
    return stoi(tmp);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;
    cout << solution(to_string(solution(s1) + solution(s2)));
}