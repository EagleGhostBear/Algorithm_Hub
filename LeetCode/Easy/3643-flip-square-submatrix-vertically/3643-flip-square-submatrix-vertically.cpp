class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> ans = grid;
        for(int i=0; i<k/2; i++){
            vector<int> tmp = ans[x + i];
            for(int j=0; j<k; j++){
                ans[x + i][y + j] = ans[x + k - 1 - i][y + j];
                ans[x + k - 1 - i][y + j] = tmp[y + j];
            }
        }
        return ans;
    }
};