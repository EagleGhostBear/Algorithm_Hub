class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans(grid.size() - k + 1, vector<int>(grid[0].size() - k + 1));

        for(int i=0; i<ans.size(); i++) for(int j=0; j<ans[i].size(); j++){
            int val = 1e6;
            map<int, int> m;
            for(int row=0; row<k; row++) for(int col=0; col<k; col++){
                m[grid[i + row][j + col]]++;
            }
            if(m.size() == 1) val = 0;
            else{
                int prev = 1e6;
                for(auto it = m.rbegin(); it != m.rend(); it++){
                    val = min(val, prev - it->first);
                    prev = it->first;
                }
            }
            ans[i][j] = val;
        }
        return ans;
    }
};