class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        vector<vector<int>> v = grid;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(i) v[i][j] += v[i - 1][j];
                if(j) v[i][j] += v[i][j - 1];
                if(i && j) v[i][j] -= v[i - 1][j - 1];
                if(v[i][j] <= k) ans++;
                else break;
            }
        }
        return ans;
    }
};