class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int ans = -1e4;
        int rs = grid.size(), cs = grid[0].size();
        if(rs == 1 && cs == 1) return 0;
        vector<vector<vector<int>>> dp(rs, vector<vector<int>>(cs, vector<int>(k + 1, -1e4)));
        dp[0][0][k] = 0;
        for(int i=0; i<rs; i++) for(int j=0; j<cs; j++){
            if(grid[i][j]){
                // 상
                if(i) for(int t=k - 1; t>-1; t--) dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j][t + 1] + grid[i][j]);
                // 좌
                if(j) for(int t=k - 1; t>-1; t--) dp[i][j][t] = max(dp[i][j][t], dp[i][j - 1][t + 1] + grid[i][j]);
            }
            else{
                // 상
                if(i) for(int t=k; t>-1; t--) dp[i][j][t] = max(dp[i][j][t], dp[i - 1][j][t]);
                if(j) for(int t=k; t>-1; t--) dp[i][j][t] = max(dp[i][j][t], dp[i][j - 1][t]);
            }
        }
        for(int i=0; i<=k; i++) ans = max(ans, dp[rs - 1][cs - 1][i]);
        if(ans < 0) return -1;
        return ans;
    }
};
// 200 * 200 * 1000