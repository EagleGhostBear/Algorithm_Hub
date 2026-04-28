class Solution {
public:
    vector<int> v;
    int find(int idx){
        if(v[idx] == idx) return idx;
        return v[idx] = find(v[idx]);
    }
    void unionAB(int a, int b){
        int rootA = find(a);
        int rootB = find(b);
        if(rootA != rootB){
            v[rootA] = rootB;
        }
        return;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int ans = 0, sz = source.size();
        v.assign(sz, 0);
        for(int i=1; i<sz; i++) v[i] = i;
        for(int i=0; i<allowedSwaps.size(); i++){
            unionAB(allowedSwaps[i][0], allowedSwaps[i][1]);
        }
        vector<vector<int>> gp(sz, vector<int>());
        for(int i=0; i<sz; i++) gp[find(i)].push_back(i);
        for(int i=0; i<sz; i++){
            if(gp[i].size() == 1){
                if(source[i] != target[i]) ans++;
            }
            else{
                unordered_map<int, int> um;
                for(auto idx : gp[i]) {um[source[idx]]++; um[target[idx]]--;}
                int cnt = 0;
                for(auto n : um) if(n.second > 0) cnt += n.second;
                ans += cnt;
            }
        }
        return ans;
    }
};