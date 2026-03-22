class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<vector<int>>> rotat(4, vector<vector<int>>(mat.size(), vector<int>(mat[0].size(), 0)));
        rotat[0] = mat;
        if(rotat[0] == target) return true;
        for(int t=0; t<3; t++){
            for(int i=0; i<mat.size(); i++) for(int j=0; j<mat[i].size(); j++){
                int nr = j;
                int nc = abs(i - ((int)mat.size() - 1));
                rotat[t + 1][nr][nc] = rotat[t][i][j];
            }
            if(rotat[t + 1] == target) return true;
        }
        return false;
    }
};