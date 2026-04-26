class Solution {
public:
    struct node{
        int row, col, dir;
    };
    bool containsCycle(vector<vector<char>>& grid) {
        int rs = grid.size(), cs = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<bool>> visited(rs, vector<bool>(cs));
        queue<node> q;

        for(int i=0; i<rs; i++) for(int j=0; j<cs; j++){
            if(visited[i][j]) continue;
            visited[i][j] = true;
            q.push({i, j, 5});
            while(q.size()){
                node now = q.front(); q.pop();

                for(int i=0; i<4; i++){
                    if(i == now.dir) continue;
                    int nr = now.row + dr[i];
                    int nc = now.col + dc[i];
                    if(nr < 0 || nc < 0 || nr >= rs || nc >= cs) continue;
                    if(grid[nr][nc] != grid[now.row][now.col]) continue;
                    if(visited[nr][nc]) return true;
                    visited[nr][nc] = true;
                    q.push({nr, nc, (i + 2) % 4});
                }
            }
        }
        return false;
    }
};