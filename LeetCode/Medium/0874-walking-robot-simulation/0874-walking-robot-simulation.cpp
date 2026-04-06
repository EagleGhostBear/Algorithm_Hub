class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        pair<int, int> point = {0, 0};
        unordered_map<int, unordered_map<int, bool>> ob;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int dir = 0;
        for(int i=0; i<obstacles.size(); i++) ob[obstacles[i][0]][obstacles[i][1]] = true;
        for(int i=0; i<commands.size(); i++){
            if(commands[i] < 0){
                if(commands[i] == -1){
                    dir = (dir + 1 > 3 ? 0 : dir + 1);
                }
                else if(commands[i] == -2){
                    dir = (dir - 1 < 0 ? 3 : dir - 1);
                }
            }
            else{
                int t = commands[i];
                for(int j=0; j<commands[i]; j++){
                    int nr = point.first + dr[dir];
                    int nc = point.second + dc[dir];
                    if(ob[nr][nc]) break;
                    point = {nr, nc};
                }
                ans = max(ans, (int)pow(point.first, 2) + (int)pow(point.second, 2));
            }
        }
        return ans;
    }
};