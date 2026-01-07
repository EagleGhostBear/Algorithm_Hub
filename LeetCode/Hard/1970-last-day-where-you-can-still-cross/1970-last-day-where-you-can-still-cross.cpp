class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    bool bfs(vector<vector<int>>& board, int row, int col, pair<int, int> p){
        int val = board[p.first][p.second];
        queue<pair<int, int>> q;
        q.push(p);
        while(q.size()){
            pair<int, int> now = q.front(); q.pop();
            for(int j=0; j<4; j++){
                int nr = now.first + dr[j];
                int nc = now.second + dc[j];
                if(nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
                if(board[nr][nc] > 1 && board[nr][nc] != val) return true;
                else if(board[nr][nc]) continue;
                board[nr][nc] = val;
                q.push({nr, nc});
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans = 0;
        vector<vector<int>> board(row, vector<int>(col, 1));

        for(int i=cells.size() - 1; i>-1; i--){
            if(cells[i][0] - 1 == 0){
                board[cells[i][0] - 1][cells[i][1] - 1] = 2;
                if(bfs(board, row, col, {cells[i][0] - 1, cells[i][1] - 1})) {ans=i; break;}
            }
            else if(cells[i][0] - 1 == row - 1){
                board[cells[i][0] - 1][cells[i][1] - 1] = 3;
                if(bfs(board, row, col, {cells[i][0] - 1, cells[i][1] - 1})) {ans=i; break;}
            }
            else{
                unordered_map<int, bool> color;
                for(int j=0; j<4; j++){
                    int nr = cells[i][0] - 1 + dr[j];
                    int nc = cells[i][1] - 1 + dc[j];
                    if(nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
                    if(board[nr][nc] < 2) continue;
                    color[board[nr][nc]] = true;
                }
                if(color.size() > 1) {ans=i; break;}
                else if(color.size() == 1){
                    board[cells[i][0] - 1][cells[i][1] - 1] = color.begin()->first;
                    if(bfs(board, row, col, {cells[i][0] - 1, cells[i][1] - 1})) {ans=i; break;}
                }
                else board[cells[i][0] - 1][cells[i][1] - 1] = 0;
            }
        }
        return ans;
    }
};
/*
호수 = 1
위에서 시작하는 bfs = 2
아래에서 시작하는 bfs = 3
cells를 뒤에서 부터 시작하면서 cells[i] = 2로 하고 4방향에 1이 있나 확인
*/