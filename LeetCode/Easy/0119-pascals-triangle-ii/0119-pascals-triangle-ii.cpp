class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex + 1, vector<int>());
        ans[0].push_back({1});
        for(int i=1; i<rowIndex + 1; i++){
            vector<int> row(i + 1, 1);
            for(int j=1; j<i; j++){
                row[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans[i] = row;
        }
        return ans[rowIndex];
    }
};