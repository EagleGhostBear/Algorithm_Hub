struct node{
    int row, col, dir;
};

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int ans = m * n;
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int i=0; i<walls.size(); i++){
            v[walls[i][0]][walls[i][1]] = 3;
            ans--;
        }
        for(int i=0; i<guards.size(); i++){
            v[guards[i][0]][guards[i][1]] = 2;
            ans--;
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<guards.size(); i++){
            int row = guards[i][0];
            int col = guards[i][1];
            queue<node> q;
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(v[nr][nc] > 1) continue;

                if(v[nr][nc] == 0) ans--;
                v[nr][nc] = 1;
                q.push({nr, nc, i});
            }
            while(q.size()){
                node now = q.front();
                q.pop();

                int nr = now.row + dr[now.dir];
                int nc = now.col + dc[now.dir];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(v[nr][nc] > 1) continue;

                if(v[nr][nc] == 0) ans--;
                v[nr][nc] = 1;
                q.push({nr, nc, now.dir});
            }
        }
        return ans;
    }
};