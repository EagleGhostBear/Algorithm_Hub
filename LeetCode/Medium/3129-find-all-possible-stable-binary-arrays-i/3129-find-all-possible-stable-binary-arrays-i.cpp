class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int sz = zero + one, mod = 1e9 + 7;
        // dp[idx][0개수][0, 1] = 경우의 수 // 1의개수는 어차피 idx - 0의 개수이므로 한차원 내린다.
        vector<vector<vector<int>>> dp(sz + 1, vector<vector<int>>(zero + 1, vector<int>(2, 0)));
        dp[0][0][0] = 1, dp[0][0][1] = 1;
        for(int idx=1; idx<=sz; idx++){ // 400 * 200 * 200 = 16,000,000
            for(int z=0; z<=zero; z++){
                if(z > idx) break;
                int o = idx - z;
                if(o > one) continue;
                for(int t=1; t<=min(limit, idx); t++){
                    // zero가 연속해서 t개 사용된 상황
                    if(z - t >= 0) dp[idx][z][0] = ((long long)dp[idx][z][0] + dp[idx - t][z - t][1]) % mod;
                    // one 이 연속해서 t개 사용된 상황
                    dp[idx][z][1] = ((long long)dp[idx][z][1] + dp[idx - t][z][0]) % mod;
                }
            }
        }
        return ((long long)dp[sz][zero][0] + dp[sz][zero][1]) % mod;
    }
};
/*
0 = zero개, 1 = one개를 가지고 조합을 하는데 연속된게 limit 를 넘으면 안되는 문제
dp?
dp[idx][zero][one][0, 1]
dp[400][200][200][2]
*/