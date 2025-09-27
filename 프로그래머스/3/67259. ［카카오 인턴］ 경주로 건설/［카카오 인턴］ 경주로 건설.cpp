#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<vector<int>>> dp; // dp[row][col][가로직선,세로직선,가로직각,세로직각]

int solution(vector<vector<int>> board) {
    dp.resize(board.size(), vector<vector<int>>(board[0].size(), vector<int>(4, 1e6)));
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nc < 0 || nr >= board.size() || nc >= board[0].size()) continue;
            if(board[nr][nc]) continue; // 벽
            
            bool chk = false;
            if(i % 2){ // 가로
                // 직선도로
                int minv = min(dp[now.first][now.second][0] + 100, dp[now.first][now.second][3] + 100);
                if(dp[nr][nc][0] > minv){
                    dp[nr][nc][0] = minv;
                    chk = true;
                }
                // 직각도로
                minv = min(dp[now.first][now.second][0] + 600, dp[now.first][now.second][3] + 600);
                if(dp[nr][nc][2] > minv){
                    dp[nr][nc][2] = minv;
                    chk = true;
                }
            }
            else{ // 세로
                // 직선도로
                int minv = min(dp[now.first][now.second][1] + 100, dp[now.first][now.second][2] + 100); // 세로직선, 가로직각
                if(dp[nr][nc][1] > minv){
                    dp[nr][nc][1] = minv;
                    chk = true;
                }
                // 직각도로
                minv = min(dp[now.first][now.second][1] + 600, dp[now.first][now.second][2] + 600);
                if(dp[nr][nc][3] > minv){
                    dp[nr][nc][3] = minv;
                    chk = true;
                }
            }
            if(chk) q.push({nr, nc});
        }
    }
    int ans = 1e6;
    for(int i=0; i<4; i++) ans = min(ans, dp[board.size() - 1][board[0].size() - 1][i]);
    return ans;
}
/*
bfs? 근데 비용이 우선순위라 가까운게 장땡이 아님
*/