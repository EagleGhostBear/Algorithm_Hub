class Solution {
public:
    int mod = 1e9 + 7;
    void solve(vector<int>& nums, vector<int>& queries){
        for(int i=queries[0]; i<=queries[1]; i+=queries[2]){
            nums[i] = ((long long)nums[i] * queries[3]) % mod;
        }
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i=0; i<queries.size(); i++){
            solve(nums, queries[i]);
        }
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++) ans ^= nums[i];
        return ans;
    }
};