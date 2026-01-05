class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int minVal = 1e5, cntMinus = 0;
        bool cntZero = false;
        for(int i=0; i<matrix.size(); i++) for(int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j] < 0) cntMinus++;
            else if(matrix[i][j] == 0) cntZero = true;

            ans += abs(matrix[i][j]);
            minVal = min(minVal, abs(matrix[i][j]));
        }

        if(cntMinus % 2 && !cntZero) ans -= (minVal * 2);
        return ans;
    }
};