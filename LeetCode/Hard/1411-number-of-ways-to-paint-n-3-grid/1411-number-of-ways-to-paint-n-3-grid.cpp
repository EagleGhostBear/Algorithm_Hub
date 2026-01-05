typedef long long ll;

class Solution {
public:
    int numOfWays(int n) {
        int ans = 0, mod = 1e9 + 7;
        vector<vector<ll>> dp(n, vector<ll>(2, 0)); // dp[col][abc, aba] = 가능한 개수
        dp[0][0] = 6, dp[0][1] = 6;
        for(int col=1; col<n; col++){
            dp[col][0] = (dp[col - 1][0] * 2 + dp[col - 1][1] * 2) % mod; // abc
            dp[col][1] = (dp[col - 1][0] * 2 + dp[col - 1][1] * 3) % mod; // aba
        }
        ans += (dp[n - 1][0] + dp[n - 1][1]) % mod;
        return ans;
    }
};
/*
세로 경우의수

3가지수 쓰는 경우
3 2 1 = 6

2가지수 쓰는 경우
3 2 1 = 6

한라인에 총 12개

A | B C B  B C
B | A A C  A A
A | B C B  C B 
---
6 * 5

A | B C  B B
B | C A  A C
C | A B  B B
---
6 * 4
*/