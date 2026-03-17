class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> v(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<map<int, int>> row(matrix.size(), map<int, int>());
        for(int i=0; i<matrix[0].size(); i++){
            for(int j=0; j<matrix.size(); j++){
                if(matrix[j][i]){
                    if(j) v[j][i] = v[j - 1][i];
                    v[j][i] += 1;
                    row[j][v[j][i]]++;
                }
            }
        }
        for(int i=0; i<row.size(); i++){
            int cnt = 0;
            for(auto it=row[i].rbegin(); it != row[i].rend(); it++){
                cnt += it->second;
                ans = max(ans, it->first * cnt);
            }
        }
        return ans;
    }
};