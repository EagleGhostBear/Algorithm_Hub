#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> lands;
vector<int> oil(1);

void bfs(int row, int col, int color){
    int cnt = 1;
    v[row][col] = color;
    queue<pair<int, int>> q;
    q.push({row, col});
    
    int dr[] = {-1 , 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size()) continue;
            if(v[nr][nc] || !lands[nr][nc]) continue;
            
            v[nr][nc] = color;
            cnt++;
            q.push({nr, nc});
        }
    }
    oil.push_back(cnt);
    return;
}

int solution(vector<vector<int>> land) {
    v.resize(land.size(), vector<int>(land[0].size(), 0));
    int color = 1;
    lands = land;
    for(int i=0; i<land.size(); i++){
        for(int j=0; j<land[i].size(); j++){
            if(!v[i][j] && land[i][j]) bfs(i, j, color++);
        }
    }
    
    int ans = 0;
    for(int col = 0; col<land[0].size(); col++){
        vector<int> visited(oil.size());
        int total = 0;
        for(int row=0; row<land.size(); row++){
            int color = v[row][col];
            if(color && !visited[color]){
                visited[color] = 1;
                total += oil[color];
            }
        }
        ans = max(ans, total);
    }
    return ans;
}