class Solution {
public:
    int calSize(int row, int col, int len, vector<vector<int>>& grid){
        if(row - len < 0 || row + len >= grid.size() || col - len < 0 || col + len >= grid[0].size()) return 0;
        if(len == 0) return grid[row][col];
        int ret = 0;
        pair<int, int> p = {row - len, col};
        int dr[] = {1,1,-1,-1};
        int dc[] = {1,-1,-1,1};
        for(int dir=0; dir<4; dir++) for(int i=0; i<len; i++){
            p.first += dr[dir], p.second += dc[dir];
            ret += grid[p.first][p.second];
        }
        return ret;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        priority_queue<int> pq;
        unordered_map<int, bool> um;
        um[0] = true;
        int maxLen = (min(grid.size(), grid[0].size()) - 1) / 2;
        for(int i=0; i<grid.size(); i++) for(int j=0; j<grid[i].size(); j++){
            for(int len=0; len<=maxLen; len++){
                int val = calSize(i, j, len, grid);
                if(um[val]) continue;
                um[val] = true;
                pq.push(val);
            }
        }
        while(ans.size() < 3 && pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
/*
가능한 가장큰 마름모의 한변의 길이는 = (grid.size() - 1) / root(2)
가장 작은 마름모의 한변의 길이는 = 0
*/