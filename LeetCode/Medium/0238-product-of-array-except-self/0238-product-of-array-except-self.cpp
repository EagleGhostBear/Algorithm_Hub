class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size()), left(nums.size()), right(nums.size());
        left.front() = nums.front(), right.back() = nums.back();
        for(int i=1; i<nums.size(); i++) left[i] = left[i - 1] * nums[i];
        for(int i=nums.size() - 2; i>-1; i--) right[i] = right[i + 1] * nums[i];
        for(int i=0; i<nums.size(); i++){
            ans[i] = (i ? left[i - 1] : 1) * (i<nums.size() - 1 ? right[i + 1] : 1);
        }
        return ans;
    }
};