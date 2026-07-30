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
        if(rootA != rootB){v[rootA] = rootB;}
    }

    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        v.resize(n);
        vector<bool> ans(queries.size());

        for(int i=0; i<n; i++) v[i] = i;
        for(int i=0; i<n; i++){
            for(int j=i-1; j>-1; j--){
                if(nums[i] - nums[j] > maxDiff || find(i) == find(j)) break;
                unite(i, j);
            }
        }
        for(int i=0; i<queries.size(); i++){
            if(find(queries[i][0]) == find(queries[i][1])) ans[i] = true;
            else ans[i] = false;
        }
        return ans;
    }
};