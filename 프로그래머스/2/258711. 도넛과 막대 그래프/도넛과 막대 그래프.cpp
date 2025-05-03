#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> type(1000001, -1); // -1: 타입X, 0: 정점, 1: 도넛, 2: 막대, 3: 8자
vector<vector<int>> edge(1000001);
vector<int> ans(4, 0); // 정점, 도넛, 막대, 8자

void bfs(int point){
    queue<int> q;
    unordered_map<int, int> um;
    q.push(point);
    um[point]++;
    while(q.size()){
        int now = q.front();
        q.pop();
        
        for(int i=0; i<edge[now].size(); i++){
            int next = edge[now][i];
            um[next]++;
            if(um[next] > 1) continue;
            q.push(next);
        }
    }
    
    if(um[point] == 1){ // 막대
        ans[2]++;
        return;
    }
    else{
        for(auto data : um){
            if(point != data.first && um[point] - 1 != data.second){ // 8자
                ans[3]++;
                return;
            }
        }
    }
    // 도넛
    ans[1]++;
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    for(int i=0; i<edges.size(); i++){
        int from = edges[i][0];
        int to = edges[i][1];
        if(type[from] < 0) type[from] = 0;
        type[to] = 2;
        edge[from].push_back(to);
    }
    // 정점 찾기
    for(int i=1; i<type.size(); i++) if(type[i] == 0 && edge[i].size() > 1){
        ans[0] = i;
        break;
    }
    
    // 정점
    for(int i=0; i<edge[ans[0]].size(); i++){
        int now = edge[ans[0]][i];
        bfs(now);
    }
    return ans;
}
/*
생성 정점: 아무도 해당 점을 안가르킴
반복O : 도넛(1사이클에 전부 1번만), 8자(누군가 사이클에서 2번 이상)
반복X : 막대
*/