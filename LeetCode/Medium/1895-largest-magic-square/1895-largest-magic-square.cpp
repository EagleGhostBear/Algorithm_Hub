class Solution {
public:
    int is_row(vector<vector<int>>& sumRow, int& row, int& col, int& len){
        int prev = sumRow[row + len - 1][col] - (row ? sumRow[row - 1][col] : 0);
        for(int i=1; i<len; i++){
            int nc = col + i;
            if(prev != sumRow[row + len - 1][nc] - (row ? sumRow[row - 1][nc] : 0)) return -1;
        }
        return prev;
    }
    int is_col(vector<vector<int>>& sumCol, int& row, int& col, int& len){
        int prev = sumCol[row][col + len - 1] - (col ? sumCol[row][col - 1] : 0);
        for(int i=1; i<len; i++){
            int nr = row + i;
            if(prev != sumCol[nr][col + len - 1] - (col ? sumCol[nr][col - 1] : 0)) return -1;
        }
        return prev;
    }
    int is_slab(vector<vector<int>>& grid, int& row, int& col, int& len){
        int slab1 = 0, slab2 = 0;
        for(int i=0; i<len; i++){
            slab1 += grid[row + i][col + i];
            slab2 += grid[row + i][col + len - 1 - i];
        }
        if(slab1 == slab2) return slab1;
        return -1;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int ans = 1;
        vector<vector<int>> sumRow(grid.size(), vector<int>(grid[0].size()));
        vector<vector<int>> sumCol(grid.size(), vector<int>(grid[0].size()));
        for(int row=0; row<grid.size(); row++) for(int col=0; col<grid[row].size(); col++){
            sumRow[row][col] = grid[row][col] + (row ? sumRow[row - 1][col] : 0);
            sumCol[row][col] = grid[row][col] + (col ? sumCol[row][col - 1] : 0);
        }
        for(int row=0; row<grid.size(); row++){
            for(int col=0; col<grid[row].size(); col++){
                for(int len=2; len<=50; len++){
                    if(row + len > grid.size() || col + len > grid[0].size()) break;
                    int rowVal = is_row(sumRow, row, col, len);
                    if(rowVal < 0) continue;
                    int colVal = is_col(sumCol, row, col, len);
                    if(colVal < 0 || (rowVal != colVal)) continue;
                    if(rowVal == is_slab(grid, row, col, len)){
                        ans = max(ans, len);
                    }
                }
            }
        }
        return ans;
    }
};
/*
최대 50 * 50 = 2,500
매 좌표에서 확장해나가면서 len = 1,2,3,...,50까지
*/