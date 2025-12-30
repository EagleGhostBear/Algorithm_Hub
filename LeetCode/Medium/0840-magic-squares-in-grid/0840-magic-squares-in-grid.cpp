class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for(int row=1; row<grid.size() - 1; row++){
            for(int col=1; col<grid[row].size() - 1; col++){
                unordered_map<int, bool> um;
                for(int i=0; i<3; i++) for(int j=0; j<3; j++){
                    int now = grid[i + row - 1][j + col - 1];
                    if(now < 1 || now > 9) continue;
                    um[now] = true;
                }
                if(um.size() < 9) continue;
                int base = grid[row - 1][col] + grid[row + 1][col];
                if(base != grid[row][col - 1] + grid[row][col + 1]) continue;
                else if(base != grid[row - 1][col - 1] + grid[row + 1][col + 1]) continue;
                else if(base != grid[row - 1][col + 1] + grid[row + 1][col - 1]) continue;
                base += grid[row][col];
                if(base != grid[row - 1][col - 1] + grid[row - 1][col] + grid[row - 1][col + 1]) continue;
                else if(base != grid[row + 1][col - 1] + grid[row + 1][col] + grid[row + 1][col + 1]) continue;
                else if(base != grid[row - 1][col - 1] + grid[row][col - 1] + grid[row + 1][col - 1]) continue;
                else if(base != grid[row - 1][col + 1] + grid[row][col + 1] + grid[row + 1][col + 1]) continue;
                ans++;
            }
        }
        return ans;
    }
};