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
string s = " ";
vector<vector<int>> dp; // dp[자리][0, 1] = 경우의 수
// dp[][0] = 0
// dp[][1] = 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    s = " " + s;
    dp.resize(n + 1, vector<int>(2, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        // 해당 숫자를 1자리로 보는 경우
        if(s[i] != '0') dp[i][0] += (dp[i - 1][0] + dp[i - 1][1]) % 1000000;
        // 해당 숫자를 2자리로 보는 경우
        string sub_s = s.substr(i - 1, 2);
        if (i - 2 >= 0 && sub_s.size() == 2 && sub_s[0] != '0' && stoi(sub_s) < 27) {
            //cout << "chk: " << s.substr(i - 1, 2) << endl;
            dp[i][1] += (dp[i - 2][0] + dp[i - 2][1]) % 1000000;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % 1000000;
}
/*
0처리 주의
1 ~ 26
0 이 나올수 있는 경우
10, 20
*/