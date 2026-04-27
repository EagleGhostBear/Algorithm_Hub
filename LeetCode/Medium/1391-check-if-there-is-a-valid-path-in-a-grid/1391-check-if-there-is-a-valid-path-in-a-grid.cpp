class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int rs = grid.size(), cs = grid[0].size();
        vector<vector<bool>> visited(rs, vector<bool>(cs));
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        bool routeOut[7][4] = {{0,0,0,0},{0,1,0,1},{1,0,1,0},{0,0,1,1},{0,1,1,0},{1,0,0,1},{1,1,0,0}};
        bool routeIn[7][4] = {{0,0,0,0},{0,1,0,1},{1,0,1,0},{1,1,0,0},{1,0,0,1},{0,1,1,0},{0,0,1,1}}; // 다음 진행타일에 대해 접근 가능한 방향
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while(q.size()){
            pair<int, int> now = q.front(); q.pop();
            int nowStreet = grid[now.first][now.second];

            for(int i=0; i<4; i++){
                if(!routeOut[nowStreet][i]) continue;
                int nr = now.first + dr[i];
                int nc = now.second + dc[i];
                if(nr < 0 || nc < 0 || nr >= rs || nc >= cs) continue;
                if(visited[nr][nc]) continue;
                int nextStreet = grid[nr][nc];
                if(routeIn[nextStreet][i] == 0) continue;

                visited[nr][nc] = true;
                if(nr == rs - 1 && nc == cs - 1) return true;
                q.push({nr, nc});
            }
        }
        if(visited[rs - 1][cs - 1]) return true;
        return false;
    }
};