class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size();
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < n; j++){
                int idx = (i % 2 != 0 ? j + k : j - k);
                idx = (idx % n + n) % n;
                if(mat[i][j] != mat[i][idx]) return false;
            }
        }
        return true;
    }
};