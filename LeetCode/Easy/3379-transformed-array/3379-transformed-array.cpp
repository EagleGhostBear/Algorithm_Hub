class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int sz = nums.size();
        for(int i=0; i<sz; i++){
            int idx = ((i + nums[i]) % sz + sz) % sz;
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};