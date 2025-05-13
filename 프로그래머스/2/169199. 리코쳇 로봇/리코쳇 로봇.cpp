#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;
pair<int, int> start, goal;

void bfs(int row, int col){
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 0;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        pair<int, int> now = q.front();
        q.pop();
        if(now == goal) continue;
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            while(!(nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size() || v[nr][nc])){
                nr += dr[i], nc += dc[i];
            }
            nr -= dr[i], nc -= dc[i];
            if(visited[nr][nc] <= visited[now.first][now.second] + 1) continue;
            visited[nr][nc] = visited[now.first][now.second] + 1;
            q.push({nr, nc});
        }
    }
}

int solution(vector<string> board) {
    v.resize(board.size(), vector<int>(board[0].size(), 0));
    visited.resize(board.size(), vector<int>(board[0].size(), 1e9));
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'D') v[i][j] = 1;
            else if(board[i][j] == 'R') start = {i, j};
            else if(board[i][j] == 'G') goal = {i, j};
        }
    }
    
    bfs(start.first, start.second);
    
    if(visited[goal.first][goal.second] == 1e9) return -1;
    return visited[goal.first][goal.second];
}