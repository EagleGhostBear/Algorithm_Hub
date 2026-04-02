class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        vector<long long> rowTot(grid.size()), colTot(grid[0].size());
        for(int i=0; i<grid.size(); i++){
            if(i) rowTot[i] = rowTot[i - 1];
            for(int j=0; j<grid[i].size(); j++){
                rowTot[i] += grid[i][j];
                colTot[j] += grid[i][j];
            }
        }
        for(int i=0; i<rowTot.size() - 1; i++) if(rowTot[i] == rowTot.back() - rowTot[i]) return true;
        for(int i=1; i<colTot.size(); i++) colTot[i] += colTot[i - 1];
        for(int i=0; i<colTot.size() - 1; i++) if(colTot[i] == colTot.back() - colTot[i]) return true;
        return false;
    }
};