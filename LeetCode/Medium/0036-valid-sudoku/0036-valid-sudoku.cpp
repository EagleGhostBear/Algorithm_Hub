class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            vector<bool> row(9), col(9), quad(9);
            for(int j=0; j<9; j++){ // 가로
                int num = board[i][j] - '0';
                if(num < 0) continue;
                if(row[num]) return false;
                row[num] = true;
            }
            for(int j=0; j<9; j++){ // 세로
                int num = board[j][i] - '0';
                if(num < 0) continue;
                if(col[num]) return false;
                col[num] = true;
            }
            int m = ((i * 3) / 9) * 3, n = (i * 3) % 9;
            for(int l=0; l<3; l++) for(int k=0; k<3; k++){
                int num = board[m + l][n + k] - '0';
                if(num < 0) continue;
                if(quad[num]) return false;
                quad[num] = true;
            }
        }
        return true;
    }
};