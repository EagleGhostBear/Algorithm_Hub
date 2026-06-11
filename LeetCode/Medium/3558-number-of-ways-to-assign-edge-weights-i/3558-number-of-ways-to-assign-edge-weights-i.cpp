class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int ans = 1, depth = 0, mod = 1e9 + 7, sz = edges.size() + 1; 
        vector<vector<int>> v(sz + 1, vector<int>());
        vector<bool> visited(sz + 1);
        for(int i=0; i<edges.size(); i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = true;
        while(q.size()){
            pair<int, int> now = q.front(); q.pop();
            depth = max(depth, now.second);
            for(int i=0; i<v[now.first].size(); i++){
                if(visited[v[now.first][i]]) continue;
                visited[v[now.first][i]] = true;
                q.push({v[now.first][i], now.second + 1});
            }
        }
        // depth개의 노드중 홀수를 홀수개 배치하는 콤비네이션을 계산 = 페르마의 소정리를 이용한 역원곱셈으로 풀이 -> 이를 이항정리를 통해 정리하면 = 2^(n - 1)
        if(depth < 10) return pow(2, depth - 1);
        for(int i=0; i<depth - 1; i++) ans = ans * 2 % mod;
        return ans;
    }
};