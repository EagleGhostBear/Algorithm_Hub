typedef long long ll;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size()));
        vector<ll> rowTop(grid.size()), rowBottom(grid.size());
        vector<vector<pair<ll, ll>>> colLR(grid.size(), vector<pair<ll, ll>>(grid[0].size(), pair<ll, ll>()));
        int mod = 12345;
        for(int i=0; i<grid.size(); i++){
            long long tot = 1;
            colLR[i].front().first = grid[i][0];
            colLR[i].back().second = grid[i].back();
            for(int j=0; j<grid[i].size(); j++){
                tot = (tot * grid[i][j]) % mod;
                if(j) colLR[i][j].first = (colLR[i][j - 1].first * grid[i][j]) % mod;
            }
            for(int j=grid[i].size() - 2; j>-1; j--) colLR[i][j].second = (colLR[i][j + 1].second * grid[i][j]) % mod;
            rowTop[i] = ((i ? rowTop[i - 1] : 1) * tot) % mod;
        }
        for(int i=grid.size() - 1; i>-1; i--){
            long long tot = 1;
            for(int j=0; j<grid[i].size(); j++) tot = (tot * grid[i][j]) % mod;
            rowBottom[i] = ((i < grid.size() - 1 ? rowBottom[i + 1] : 1) * tot) % mod;
        }
        for(int i=0; i<grid.size(); i++){
            long long tot = ((i ? rowTop[i - 1] : 1) * (i < grid.size() - 1 ? rowBottom[i + 1] : 1)) % mod;
            for(int j=0; j<grid[i].size(); j++){
                long long colTot = ((j ? colLR[i][j - 1].first : 1) * (j < grid[0].size() - 1 ? colLR[i][j + 1].second : 1)) % mod;
                ans[i][j] = (tot * colTot) % mod;
            }
        }
        return ans;
    }
};