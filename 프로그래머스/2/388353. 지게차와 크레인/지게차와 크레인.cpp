#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int r, c;
vector<vector<int>> v;

void func1(int target){
    queue<pair<int, int>> q;
    vector<vector<int>> visited(r + 2, vector<int>(c + 2));
    q.push({0, 0});
    visited[0][0] = 1;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        pair<int, int> now = q.front();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];
            if(nr < 0 || nc < 0 || nr >= r + 2 || nc >= c + 2) continue;
            if(visited[nr][nc]) continue;
            
            if(v[nr][nc] == target) v[nr][nc] = 0;
            else if(!v[nr][nc]) q.push({nr, nc});
            visited[nr][nc] = 1;
        }
    }
    return;
}

void func2(int target){
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            if(v[i][j] == target) v[i][j] = 0;
        }
    }
    return;
}

int solution(vector<string> storage, vector<string> requests) {
    r = storage.size(); c = storage[0].size();
    v.resize(r + 2, vector<int>(c + 2));
    for(int i=0; i<storage.size(); i++){
        for(int j=0; j<storage[i].size(); j++){
            v[i + 1][j + 1] = int(storage[i][j]);
        }
    }
    
    for(int i=0; i<requests.size(); i++){
        if(requests[i].size() == 1){
            func1(int(requests[i][0]));
        }
        else{
            func2(int(requests[i][0]));
        }
    }
    
    int answer = 0;
    for(int i=1; i<r + 1; i++) for(int j=1; j<c + 1; j++) if(v[i][j]) answer++;
    return answer;
}