#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<int> visited;

void bfs(int des){
    queue<int> q;
    q.push(des);
    visited[des] = 1;
    
    while(q.size()){
        int now = q.front();
        q.pop();
        
        for(int i=0; i<v[now].size(); i++){
            int next = v[now][i];
            if(visited[next]) continue;
            visited[next] = visited[now] + 1;
            q.push(next);
        }
    }
    return;
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    v.resize(n, vector<int>());
    visited.assign(n, 0);
    for(int i=0; i<roads.size(); i++){
        v[roads[i][0] - 1].push_back(roads[i][1] - 1);
        v[roads[i][1] - 1].push_back(roads[i][0] - 1);
    }
    bfs(destination - 1);
    vector<int> answer;
    for(int i=0; i<sources.size(); i++){
        answer.push_back(visited[sources[i] - 1] - 1);
    }
    return answer;
}
/*
단순 bfs? destination -> 모든 지점들까지
*/