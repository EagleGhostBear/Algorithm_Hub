class Solution {
public:
    vector<int> v;
    int find(int idx){
        if(v[idx] == idx) return idx;
        return v[idx] = find(v[idx]);
    }
    void unite(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB) v[rootA] = rootB;
        return;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        v.resize(n);
        vector<vector<int>> edge(n, vector<int>());
        for(int i=0; i<n; i++) v[i] = i;
        for(int i=0; i<edges.size(); i++){
            edge[edges[i][0]].push_back(edges[i][1]);
            edge[edges[i][1]].push_back(edges[i][0]);
            if(find(edges[i][0]) != find(edges[i][1])) unite(edges[i][0], edges[i][1]);
        }
        vector<vector<int>> gp(n, vector<int>());
        for(int i=0; i<n; i++) gp[find(i)].push_back(i);
        for(int i=0; i<n; i++){
            if(gp[i].size() == 0) continue;
            int chk = true, sz = gp[i].size();
            for(int j=0; j<sz; j++) if(edge[gp[i][j]].size() != sz - 1) { chk = false; break;}
            if(chk) ans++;
        }
        return ans;
    }
};