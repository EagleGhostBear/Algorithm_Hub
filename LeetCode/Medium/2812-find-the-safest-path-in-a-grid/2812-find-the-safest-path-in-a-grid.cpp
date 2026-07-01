class Solution {
public: 
    struct node{
        int row, col, w;
    };
    struct compare{
        bool operator()(node left, node right){
            if(left.w < right.w) return true;
            if(left.w > right.w) return false;
            return false;
        }
    };
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rs = grid.size(), cs = grid[0].size();
        vector<vector<int>> v(rs, vector<int>(cs, 1e9));
        queue<pair<int, int>> q;
        for(int i=0; i<rs; i++) for(int j=0; j<cs; j++) if(grid[i][j]){
            v[i][j] = 0;
            q.push({i, j});
        }
        int dr[] = {0, 1, -1, 0};
        int dc[] = {1, 0, 0, -1};
        while(q.size()){
            pair<int, int> now = q.front(); q.pop();
            for(int i=0; i<4; i++){
                int nr = now.first + dr[i];
                int nc = now.second + dc[i];
                if(nr < 0 || nc < 0 || nr >= rs || nc >= cs) continue;
                if(v[nr][nc] <= v[now.first][now.second] + 1) continue;
                v[nr][nc] = v[now.first][now.second] + 1;
                q.push({nr, nc});
            }
        }
        vector<vector<int>> len(rs, vector<int>(cs, 0));
        len[0][0] = v[0][0];
        priority_queue<node, vector<node>, compare> pq;
        pq.push({0, 0, v[0][0]});
        while(pq.size()){
            node now = pq.top(); pq.pop();

            for(int i=0; i<4; i++){
                int nr = now.row + dr[i];
                int nc = now.col + dc[i];
                if(nr < 0 || nc < 0 || nr >= rs || nc >= cs) continue;
                int w = min(len[now.row][now.col], v[nr][nc]);
                if(len[nr][nc] >= w) continue;
                len[nr][nc] = w;
                pq.push({nr, nc, w});
            }
        }
        return len[rs - 1][cs - 1];
    }
};