class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rs = grid.size(), cs = grid[0].size();
        vector<vector<int>> dp(rs, vector<int>(cs, -1));
        dp[0][0] = (grid[0][0] ? health - 1 : health);
        queue<pair<int, int>> q;
        q.push({0, 0});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(q.size()){
            pair<int, int> now = q.front(); q.pop();
            if(dp[now.first][now.second] == 0) continue;

            for(int i=0; i<4; i++){
                int nr = now.first + dr[i];
                int nc = now.second + dc[i];
                if(nr < 0 || nc < 0 || nr >= rs || nc >= cs) continue;
                if(grid[nr][nc] && dp[nr][nc] < dp[now.first][now.second] - 1){
                    dp[nr][nc] = dp[now.first][now.second] - 1;
                    q.push({nr, nc});
                }
                else if(grid[nr][nc] == 0 && dp[nr][nc] < dp[now.first][now.second]){
                    dp[nr][nc] = dp[now.first][now.second];
                    q.push({nr, nc});
                }
            }
        }
        if(dp[rs - 1][cs - 1] > 0) return true;
        return false;
    }
};