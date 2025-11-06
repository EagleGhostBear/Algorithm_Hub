class Solution {
public:
    vector<int> uf;

    int find(int idx){
        if(uf[idx] == idx) return idx;
        return uf[idx] = find(uf[idx]);
    }

    void unite(int a, int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a != root_b) uf[root_a] = root_b;
        return;
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<bool> v;
        unordered_map<int, map<int, bool>> um;
        for(int i=0; i<=c; i++){
            uf.push_back(i);
            v.push_back(true);
            um[i][i] = true;
        }
        for(int i=0; i<connections.size(); i++){
            unite(connections[i][0], connections[i][1]);
        }
        for(int i=1; i<=c; i++){
            int root_a = find(uf[i]);
            um[root_a][i] = true;
        }
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0] == 1){
                if(v[queries[i][1]]) ans.push_back(queries[i][1]);
                else{
                    int root_a = find(uf[queries[i][1]]);
                    if(um[root_a].size()){
                        ans.push_back(um[root_a].begin()->first);
                    }
                    else ans.push_back(-1);
                }
            }
            else{
                v[queries[i][1]] = false;
                int root_a = find(uf[queries[i][1]]);
                um[root_a].erase(queries[i][1]);
            }
        }
        // for(auto a : um){
        //     cout << a.first << ": ";
        //     for(auto b : a.second) cout << b.first << " ";
        //     cout << "\n";
        // }
        // for(auto c : uf) cout << c << " ";
        return ans;
    }
};