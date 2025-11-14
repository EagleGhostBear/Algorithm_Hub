class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(auto c : queries){
            for(int i=c[0]; i<=c[2]; i++) for(int j=c[1]; j<=c[3]; j++){
                v[i][j]++;
            }
        }
        return v;
    }
};