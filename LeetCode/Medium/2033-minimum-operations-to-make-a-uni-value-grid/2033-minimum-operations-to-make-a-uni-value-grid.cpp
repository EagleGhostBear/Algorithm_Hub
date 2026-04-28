class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int ans = 0;
        vector<int> v;
        for(int i=0; i<grid.size(); i++){
            v.insert(v.end(), grid[i].begin(), grid[i].end());
        }
        sort(v.begin(), v.end());
        int mod = v.front() % x;
        int mid = v.size() / 2;
        for(int i=0; i<v.size(); i++){
            if(v[i] % x != mod) return -1;
            ans += abs(v[mid] - v[i]) / x;
        }
        return ans;
    }
};