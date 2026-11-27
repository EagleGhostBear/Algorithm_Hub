class Solution {
public:
    vector<int> color;
    int find(int idx){
        if(color[idx] == idx) return idx;
        return color[idx] = find(color[idx]);
    }
    void unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB) color[rootA] = rootB;
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        color.assign(n, 0);
        vector<bool> visited(n);
        for(int i=1; i<n; i++) color[i] = i;
        vector<vector<int>> v(n, vector<int>());
        for(int i=0; i<invocations.size(); i++) v[invocations[i][0]].push_back(invocations[i][1]);

        queue<int> q;
        q.push(k);
        visited[k] = true;
        while(q.size()){
            int now = q.front(); q.pop();

            for(int i=0; i<v[now].size(); i++){
                unite(now, v[now][i]);
                if(visited[v[now][i]]) continue;
                q.push(v[now][i]);
                visited[v[now][i]] = true;
            }
        }
        for(int i=0; i<n; i++) find(i);
        bool chk = false;
        for(int i=0; i<color.size(); i++){
            if(color[i] == color[k]) continue;
            for(int j=0; j<v[i].size(); j++){
                if(color[v[i][j]] == color[k]) {chk = true; break;}
            }
            if(chk) break;
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!chk && color[i] == color[k]) continue;
            ans.push_back(i);
        }
        return ans;
    }
};