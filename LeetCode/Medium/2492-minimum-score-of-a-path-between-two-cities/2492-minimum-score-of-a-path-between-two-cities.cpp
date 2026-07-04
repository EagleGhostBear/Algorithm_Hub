class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> v(n + 1, vector<pair<int, int>>());
        vector<int> visited(n + 1, 1e5);
        for(int i=0; i<roads.size(); i++){
            v[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        int ans = 1e5;
        queue<int> q;
        q.push(1);
        while(q.size()){
            int now = q.front(); q.pop();

            for(int i=0; i<v[now].size(); i++){
                if(v[now][i].second >= visited[v[now][i].first]) continue;
                visited[v[now][i].first] = v[now][i].second;
                ans = min(ans, v[now][i].second);
                q.push(v[now][i].first);
            }
        }
        return ans;
    }
};