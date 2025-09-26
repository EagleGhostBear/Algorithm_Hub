#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    int row, col, dis;
};

bool chk_dis(int row, int col, vector<string>& place){
    queue<node> q;
    q.push({row, col, 2});
    vector<vector<bool>> visited(5, vector<bool>(5));
    visited[row][col] = true;
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(q.size()){
        node now = q.front();
        q.pop();
        if(now.dis == 0) continue;
        
        for(int i=0; i<4; i++){
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if(nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
            if(visited[nr][nc]) continue;
            visited[nr][nc] = true;
            
            if(place[nr][nc] == 'O') q.push({nr, nc, now.dis - 1});
            else if(place[nr][nc] == 'P') return true;
        }
    }
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<places.size(); i++){
        bool chk = false;
        for(int j=0; j<places[i].size(); j++){
            for(int k=0; k<places[i][j].size(); k++){
                if(places[i][j][k] == 'P') if(chk_dis(j, k, places[i])){
                    cout << i << " " << j << " " << k << "\n";
                    chk = true;
                    break;
                }
            }
            if(chk) break;
        }
        if(chk) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}