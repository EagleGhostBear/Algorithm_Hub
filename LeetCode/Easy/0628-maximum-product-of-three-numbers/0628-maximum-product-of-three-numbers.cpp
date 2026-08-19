class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums.back(), sz = nums.size();
        if(nums.back() < 0) return ans * nums[sz - 2] * nums[sz - 3];
        if(nums[0] * nums[1] > nums[sz - 2] * nums[sz - 3]) ans *= nums[0] * nums[1];
        else ans *= nums[sz - 2] * nums[sz - 3];
        return ans;
    }
};