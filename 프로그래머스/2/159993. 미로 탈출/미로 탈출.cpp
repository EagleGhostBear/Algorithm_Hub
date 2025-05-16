#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<vector<int>> v;
pair<int, int> point_s, point_e, lever;

int bfs1(){
    queue<pair<int, int>> q;
    q.push(point_s);
    vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 1e5));
    visited[point_s.first][point_s.second] = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        pair<int, int> now = q.front();
        q.pop();
        if(now == lever) continue;
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size() || v[nr][nc]) continue;
            if(visited[nr][nc] > visited[now.first][now.second] + 1){
                visited[nr][nc] = visited[now.first][now.second] + 1;
                q.push({nr, nc});
            }
        }
    }
    return visited[lever.first][lever.second];
}

int bfs2(){
    queue<pair<int, int>> q;
    q.push(lever);
    vector<vector<int>> visited(v.size(), vector<int>(v[0].size(), 1e5));
    visited[lever.first][lever.second] = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        pair<int, int> now = q.front();
        q.pop();
        if(now == point_e) continue;
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size() || v[nr][nc]) continue;
            if(visited[nr][nc] > visited[now.first][now.second] + 1){
                visited[nr][nc] = visited[now.first][now.second] + 1;
                q.push({nr, nc});
            }
        }
    }
    return visited[point_e.first][point_e.second];
}

int solution(vector<string> maps) {
    v.resize(maps.size(), vector<int>(maps[0].size()));
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[i].size(); j++){
            if(maps[i][j] == 'S') point_s = {i, j};
            else if(maps[i][j] == 'E') point_e = {i, j};
            else if(maps[i][j] == 'L') lever = {i, j};
            else if(maps[i][j] == 'X') v[i][j] = 1;
        }
    }
    
    int len1 = bfs1();
    int len2 = bfs2();
    if(len1 + len2 >= 1e5) return -1;
    else return len1 + len2;
}