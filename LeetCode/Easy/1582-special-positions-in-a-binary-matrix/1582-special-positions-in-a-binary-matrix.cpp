class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        vector<vector<pair<int, int>>> row(mat.size(), vector<pair<int, int>>()), col(mat[0].size(), vector<pair<int, int>>());
        for(int i=0; i<mat.size(); i++) for(int j=0; j<mat[i].size(); j++){
            if(mat[i][j]){
                row[i].push_back({i, j});
                col[j].push_back({i, j});
            }
        }
        for(int i=0; i<row.size(); i++){
            if(row[i].size() != 1) continue;
            if(col[row[i][0].second].size() != 1) continue;
            ans++;
        }
        return ans;
    }
};