class Solution {
public:
    struct node{
        int row, col;
    };
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>> dp(coins.size(), vector<vector<int>>(coins[0].size(), vector<int>(3, -1e9))); // dp[row][col][커버] = 최대코인
        dp[0][0][2] = coins[0][0];
        if(coins[0][0] < 0) dp[0][0][1] = 0;
        int dr[] = {0, 1};
        int dc[] = {1, 0};
        queue<node> q;
        q.push({0, 0});
        while(q.size()){
            node now = q.front(); q.pop();
            
            for(int i=0; i<2; i++){
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                if(nr >= coins.size() || nc >= coins[0].size()) continue;
                bool chk = false;
                if(coins[nr][nc] >= 0){
                    for(int t=2; t>-1; t--) if(dp[nr][nc][t] < dp[now.row][now.col][t] + coins[nr][nc]){
                        dp[nr][nc][t] = dp[now.row][now.col][t] + coins[nr][nc];
                        chk = true;
                    }
                }
                else{
                    // 막기 씀
                    for(int t=2; t>0; t--) if(dp[nr][nc][t - 1] < dp[now.row][now.col][t]){
                        dp[nr][nc][t - 1] = dp[now.row][now.col][t];
                        chk = true;
                    }
                    // 막기 안씀
                    for(int t=2; t>-1; t--) if(dp[nr][nc][t] < dp[now.row][now.col][t] + coins[nr][nc]){
                        dp[nr][nc][t] = dp[now.row][now.col][t] + coins[nr][nc];
                        chk = true;
                    }
                }
                if(chk) q.push({nr, nc});
            }
        }
        int ans = -1e9;
        for(int i=0; i<3; i++) ans = max(ans, dp.back().back()[i]);
        return ans;
    }
};