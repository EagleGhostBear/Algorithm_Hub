class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 1e9;
        vector<vector<int>> v(100001, vector<int>());
        for(int i=0; i<nums.size(); i++){
            v[nums[i]].push_back(i);
        }
        for(int i=0; i<=100000; i++){
            if(v[i].size() < 3) continue;
            for(int j=0; j<v[i].size()-2; j++){
                ans = min(ans, abs(v[i][j] - v[i][j + 1]) + abs(v[i][j] - v[i][j + 2]) + abs(v[i][j + 1] - v[i][j + 2]));
            }
        }
        if(ans >= 1e9) return -1;
        return ans;
    }
};