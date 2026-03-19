class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        vector<vector<pair<int, int>>> v(grid.size(), vector<pair<int, int>>(grid[0].size(), {0, 0})); // {x, y}
        for(int i=0; i<grid.size(); i++) for(int j=0; j<grid[i].size(); j++){
            if(i){
                v[i][j].first += v[i - 1][j].first;
                v[i][j].second += v[i - 1][j].second;
            }
            if(j){
                v[i][j].first += v[i][j - 1].first;
                v[i][j].second += v[i][j - 1].second;
            }
            if(i && j){
                v[i][j].first -= v[i - 1][j - 1].first;
                v[i][j].second -= v[i - 1][j - 1].second;
            }
            if(grid[i][j] == 'X') v[i][j].first++;
            else if(grid[i][j] == 'Y') v[i][j].second++;

            if(v[i][j].first && (v[i][j].first == v[i][j].second)) ans++;
        }
        return ans;
    }
};