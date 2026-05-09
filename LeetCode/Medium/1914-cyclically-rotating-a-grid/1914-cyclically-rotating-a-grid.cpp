class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rs = grid.size(), cs = grid[0].size();
        vector<vector<int>> ans(rs, vector<int>(cs));
        int sz = min(rs / 2, cs / 2);
        int dr[] = {1,0,-1,0};
        int dc[] = {0,1,0,-1};
        for(int i=0; i<sz; i++){
            int nRow = rs - 2 * i - 1;
            int nCol = cs - 2 * i - 1;
            int cycle = 2 * (nRow + nCol);
            vector<int> v;
            pair<int, int> p = {i, i};
            for(int j=0; j<4; j++){
                if(j % 2){
                    for(int t=0; t<nCol; t++){
                        v.push_back(grid[p.first][p.second]);
                        p.first = p.first + dr[j];
                        p.second = p.second + dc[j];
                    }
                }
                else{
                    for(int t=0; t<nRow; t++){
                        v.push_back(grid[p.first][p.second]);
                        p.first = p.first + dr[j];
                        p.second = p.second + dc[j];
                    }
                }
            }
            p = {i, i};
            int nowK = k % cycle;
            if(nowK) nowK = cycle - nowK;
            for(int j=0; j<cycle; j++){
                int now = (nowK + j >= cycle ? nowK + j - cycle : nowK + j);
                ans[p.first][p.second] = v[now];
                if(j < nRow){
                    p.first = p.first + dr[0];
                    p.second = p.second + dc[0];
                }
                else if(j < nRow + nCol){
                    p.first = p.first + dr[1];
                    p.second = p.second + dc[1];
                }
                else if(j < nRow + nRow + nCol){
                    p.first = p.first + dr[2];
                    p.second = p.second + dc[2];
                }
                else{
                    p.first = p.first + dr[3];
                    p.second = p.second + dc[3];
                }
            }
        }
        return ans;
    }
};