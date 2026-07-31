class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rs = grid.size(), cs = grid[0].size(), sz = rs * cs;
        k %= sz;
        vector<int> v;
        vector<vector<int>> ans(rs, vector<int>(cs));
        for(int i=0; i<rs; i++) v.insert(v.end(), grid[i].begin(), grid[i].end());
        for(int i=0; i<rs; i++) for(int j=0; j<cs; j++){
            int idx = (i * cs + j - k + sz) % sz;
            ans[i][j] = v[idx];
        }
        return ans;
    }
};