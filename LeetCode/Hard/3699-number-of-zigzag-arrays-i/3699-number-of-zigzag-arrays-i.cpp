class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(r + 1, vector<int>(2, 0))); // dp[2줄][l-r숫자][0,1 하락or 증가세] = 총 경우의 수
        for(int i=l; i<=r; i++) dp[0][i][0] = 1, dp[0][i][1] = 1;
        dp[0][l][0] = 0, dp[0][r][1] = 0;

        for(int i=1; i<n; i++){
            long long prevDown = 0, prevUp = 0; // 실시간 변수 누적 방식
            for(int j=l; j<=r; j++) prevDown += dp[0][j][0];
            for(int j=l; j<=r; j++){
                prevDown -= dp[0][j][0];
                dp[1][j][0] = prevUp;
                dp[1][j][1] = prevDown % mod;
                prevUp = (prevUp + dp[0][j][1]) % mod;
            }
            dp[1][r][1] = 0;
            swap(dp[0], dp[1]);
        }
        int ans = 0;
        for(int i=l; i<=r; i++) ans = ((long long)ans + dp[0][i][0] + dp[0][i][1]) % mod;
        return ans;
    }
};