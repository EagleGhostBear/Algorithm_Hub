class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int ans = -1e4;
        int rs = grid.size(), cs = grid[0].size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(cs, vector<int>(k + 1, -1e4))); // 2 * 200 * 1000 = 40,000,000
        dp[0][0][k] = 0;
        for(int i=1; i<cs; i++){ // row = 0 정의
            if(grid[0][i]) for(int t=k - 1; t>-1; t--) dp[0][i][t] = max(dp[0][i][t], dp[0][i - 1][t + 1] + grid[0][i]);
            else for(int t=k; t>-1; t--) dp[0][i][t] = max(dp[0][i][t], dp[0][i - 1][t]);
        }
        for(int i=1; i<rs; i++){
            for(int j=0; j<cs; j++){
                if(grid[i][j]){
                    // 상
                    for(int t=k - 1; t>-1; t--) dp[1][j][t] = max(dp[1][j][t], dp[0][j][t + 1] + grid[i][j]);
                    // 좌
                    if(j) for(int t=k - 1; t>-1; t--) dp[1][j][t] = max(dp[1][j][t], dp[1][j - 1][t + 1] + grid[i][j]);
                }
                else{
                    // 상
                    for(int t=k; t>-1; t--) dp[1][j][t] = max(dp[1][j][t], dp[0][j][t]);
                    // 좌
                    if(j) for(int t=k; t>-1; t--) dp[1][j][t] = max(dp[1][j][t], dp[1][j - 1][t]);
                }
            }
            swap(dp[0], dp[1]);
            for(int j=0; j<cs; j++) fill(dp[1][j].begin(), dp[1][j].end(), -1e4);
        }
        for(int i=0; i<=k; i++) ans = max(ans, dp[0][cs - 1][i]);
        if(ans < 0) return -1;
        return ans;
    }
};