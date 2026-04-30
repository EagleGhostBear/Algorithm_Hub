class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int ans = -1e4;
        int rs = grid.size(), cs = grid[0].size();
        if(rs == 1 && cs == 1) return 0;
        vector<vector<vector<int>>> dp(rs, vector<vector<int>>(cs, vector<int>(k + 1, -1e4)));
        dp[0][0][k] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int dr[] = {0, 1};
        int dc[] = {1, 0};
        while(q.size()){
            pair<int, int> now = q.front(); q.pop();
            
            for(int i=0; i<2; i++){
                int nr = now.first + dr[i];
                int nc = now.second + dc[i];
                if(nr >= rs || nc >= cs) continue;
                bool is_bigger = false;
                if(grid[nr][nc]){
                    for(int j=k - 1; j>-1; j--) if(dp[nr][nc][j] < dp[now.first][now.second][j + 1] + grid[nr][nc]){
                        dp[nr][nc][j] = dp[now.first][now.second][j + 1] + grid[nr][nc];
                        is_bigger = true;
                    }
                }
                else{
                    for(int j=k; j>-1; j--) if(dp[nr][nc][j] < dp[now.first][now.second][j]){
                        dp[nr][nc][j] = dp[now.first][now.second][j];
                        is_bigger = true;
                    }
                }
                if(is_bigger) q.push({nr, nc});
            }
        }
        for(int i=0; i<=k; i++) ans = max(ans, dp[rs - 1][cs - 1][i]);
        if(ans < 0) return -1;
        return ans;
    }
};
// 200 * 200 * 1000