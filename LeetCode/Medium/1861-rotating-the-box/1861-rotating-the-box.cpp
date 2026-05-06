class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int rs = boxGrid.size(), cs = boxGrid[0].size();
        vector<vector<char>> ans(cs, vector<char>(rs, '.'));
        for(int row=0; row<rs; row++){
            int cnt = 0;
            for(int col=0; col<cs; col++){
                if(boxGrid[row][col] == '#') cnt++;
                else if(boxGrid[row][col] == '*'){
                    ans[col][rs - 1 - row] = '*';
                    for(int i=1; i<=cnt; i++) ans[col - i][rs - 1 - row] = '#';
                    cnt = 0;
                }
            }
            if(cnt) for(int i=1; i<=cnt; i++) ans[cs - i][rs - 1 - row] = '#';
        }
        return ans;
    }
};