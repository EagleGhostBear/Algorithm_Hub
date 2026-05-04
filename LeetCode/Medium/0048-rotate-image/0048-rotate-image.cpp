class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int sz = matrix.size() - 1;
        int rowHf = matrix.size() / 2 - 1;
        int colHf = (matrix.size() % 2 ? matrix.size() / 2 : matrix.size() / 2 - 1);
        for(int i=0; i<=rowHf; i++) for(int j=0; j<=colHf; j++){
            int row = i, col = j, prev = matrix[i][j], sv;
            for(int k=0; k<4; k++){
                int nr = col;
                int nc = sz - row;
                sv = matrix[nr][nc];
                matrix[nr][nc] = prev;
                prev = sv;
                row = nr, col = nc;
            }
        }
        return;
    }
};