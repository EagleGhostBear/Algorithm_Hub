#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct node{
    pair<int, int> loc; // 현재위치
    queue<int> target; // 목적지들이 저장된 queue
    int turn;
};

int ans = 0;
vector<vector<int>> visited(100, vector<int>(100));
vector<pair<int, int>> point;
queue<node> q;

node next_route(node now){
    // 목적지까지 도착했을때 목적지 queue에서 한개 제거
    if(now.loc == point[now.target.front()]) now.target.pop();
    // 최종 목적지까지 도착했을때
    if(now.target.empty()){
        now.loc = {-1, -1};
        return now;
    }
    
    pair<int, int> loc = now.loc;
    pair<int, int> target = point[now.target.front()];
    int diff_row = target.first - loc.first;
    int diff_col = target.second - loc.second;
    if(abs(diff_row)){ // row부터 교정
        if(abs(diff_row - 1) < abs(diff_row + 1)) now.loc.first++;
        else now.loc.first--;
    }
    else{ // col 교정
        if(abs(diff_col - 1) < abs(diff_col + 1)) now.loc.second++;
        else now.loc.second--;
    }
    now.turn++;
    return now;
}

void func(int turn){
    cout << "----" << turn << "------\n";
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    // 물류센터들 위치 저장 // points[i번째 물류센터] = {row, col}
    for(int i=0; i<points.size(); i++){
        point.push_back({points[i][0] - 1, points[i][1] - 1});
    }
    
    for(int i=0; i<routes.size(); i++){
        node tmp;
        tmp.loc = point[routes[i][0] - 1]; // 시작위치
        // 2개 이상이 겹쳤을때도 충돌위험은 1번으로 본다.
        if(++visited[tmp.loc.first][tmp.loc.second] == 2) ans++;
        for(int j=1; j<routes[i].size(); j++) tmp.target.push(routes[i][j] - 1);
        tmp.turn = 1;
        q.push(tmp);
    }
    
    int turn = 1;
    // func(0);
    visited.assign(100, vector<int>(100));
    while(q.size()){
        node now = q.front(); q.pop();
        
        // 모든 로봇이 움직였을때
        if(turn < now.turn){
            // func(turn);
            visited.assign(100, vector<int>(100));
            turn++;
        }
        node next = next_route(now);
        if(next.loc.first == -1 && next.loc.second == -1) continue;
        
        // 2개 이상이 겹쳤을때도 충돌위험은 1번으로 본다.
        if(++visited[next.loc.first][next.loc.second] == 2) ans++;
        q.push(next);
    }
    
    return ans;
}
/*
로봇은 최단 경로 이동
r좌표 이동을 우선 -> c좌표 이동
*/