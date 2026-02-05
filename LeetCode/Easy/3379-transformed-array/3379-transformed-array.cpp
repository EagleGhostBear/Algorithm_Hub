class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans;
        int sz = nums.size();
        for(int i=0; i<sz; i++){
            int val = abs(nums[i]) % sz;
            int idx = (nums[i] >= 0 ? i + val : i - val);
            if(idx >= sz) idx -= sz;
            if(idx < 0) idx += sz;
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};